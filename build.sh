#!/bin/sh
function usage() {
	echo "Usage:"
	echo "  build.sh -os [mac,linux] -arch [(space separated list of architectures, eg "i386 i586 x86_64")] [-autogen] [-configure] [-nobuild]"
	exit
}

ARCH=""
OS=""
autogen=
configure=
build=1

if [ x"$CC" == x"" ]; then
	export CC="gcc"
fi

if [ x"$CXX" == x"" ]; then
	export CXX="g++"
fi

while [[ $# -ge 1 ]]; do
	opt="$1"
	case $opt in
		-os)
			OS=$2
			shift
		;;
		-arch)
			ARCH=$2
			shift
		;;
		-autogen)
			autogen=1
			configure=1
			shift
			;;
		-configure)
			configure=1
			shift
			;;
		-nobuild)
			build=
			shift
			;;
		*)
		shift
		;;
	esac
done

if [ x"$OS" == x"" -o x"$ARCH" == x"" ]; then
	usage
fi

if [ ! -e aclocal.m4 ] ; then
	autogen=1
fi

if [ ! -e configure ] ; then
	configure=1
fi

if [ $autogen ]; then
	NOCONFIGURE=1 ./autogen.sh
fi

configureflags="--enable-maintainer-mode --enable-compile-warnings"
root=`pwd`
builddir="$root/build"
installdir="$root/install"

export CFLAGS="${CFLAGS} -O2 -g"
export CPPFLAGS="${CPPFLAGS} -O2 -g"

# backups because osx builds might tweak these
cc="${CC}"
cxx="${CXX}"
cflags="${CFLAGS}"
cxxflags="${CXXFLAGS}"

if [ x"$OS" == x"mac" ]; then
	mkdir -p tmp
	pushd tmp
	cp ../m4/libtool.patch .
	cp ../m4/libtool.m4 .
	patch -f<libtool.patch && cp libtool.m4 ../m4/ || true
	popd
	sdkpath="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk"
	sdkversion="10.9"
	cflags="$cflags -isysroot $sdkpath -mmacosx-version-min=$sdkversion"
	cxxflags="$cppflags -stdlib=libc++ -isysroot $sdkpath -mmacosx-version-min=$sdkversion"
fi

for os in $OS; do
	outputlibs=""
	osbuilddir="$builddir/$os"
	osinstalldir="$installdir/$os"
	for arch in $ARCH; do
		archbuilddir="$osbuilddir/$arch"
		archinstalldir="$osinstalldir/$arch"
		currentconfigure=$configure
		if [ ! -d $archbuilddir/Makefile ]; then
			configure=1
		fi
		mkdir -p $archbuilddir
		pushd $archbuilddir
			case $os in
				mac)
					vendor="apple"
					sys="darwin"
					export CC="${cc} -arch $arch"
					export CXX="${cxx} -arch $arch"
					export CFLAGS="${cflags} -arch $arch"
					export CXXFLAGS="${cxxflags} -arch $arch"
				;;
				linux)
					vendor="pc"
					sys="linux"
				;;
			esac
			if [ $configure ]; then
				$root/configure --host="$arch-$vendor-$sys" --prefix="$archinstalldir" $configureflags
			fi
			if [ $build ]; then
				if [ $currentconfigure ]; then
					make clean || true
				fi
				make -j 4
				make install
				make check
				if [ x"$os" == x"mac" ]; then
					install_name_tool -change "$archinstalldir/lib/libsfw.0.dylib" "@loader_path/libsfw.0.dylib" "$archbuilddir/src/sfw/.libs/libsfw.0.dylib"
					outputlibs="$outputlibs $archinstalldir/lib/libsfw.0.dylib"
				fi
			fi
		popd
		configure=$currentconfigure
	done
	if [ $build -a x"$os" == x"mac" ]; then
		lipo $outputlibs -create -output "$osinstalldir/libsfw.bundle"
	fi
done
