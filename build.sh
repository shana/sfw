#!/bin/sh -ex
ARCH=""
OS=""
autogen=
configure=
build=1

while [[ $# -gt 1 ]]; do
	opt="$1"
	case $opt in
		-os)
			OS=$opt
			shift
		;;
		-arch)
			ARCH="$ARCH $opt"
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
		;;
	esac
	shift
done

if [ ! -e configure ] ; then
	autogen=1
fi

if [ $autogen ]; then
	NOCONFIGURE=1 ./autogen.sh
fi

configureflags="--enable-maintainer-mode --enable-compile-warnings"
root=`pwd`
builddir="$root/build"
installdir="$root/install"

cxxflags="$CXXFLAGS -O2 -g"
cflags="$CFLAGS"
ldflags="$LDFLAGS"

if [ "x$os" == "xmac"]; then
	pushd m4
	patch -f<libtool.patch
	popd
	sdkpath="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk"
	sdkversion="10.9"
	cflags="$cflags -isysroot $sdkpath -mmacosx-version-min=$sdkversion"
	cxxflags="$cxxflags -stdlib=libc++ -isysroot $sdkpath -mmacosx-version-min=$sdkversion"
fi

for os in $OS; do
	outputlibs=""
	osbuilddir="$builddir/$os"
	osinstalldir="$installdir/$os"
	for arch in $ARCH; do
		archbuilddir="$osbuilddir/$arch"
		archinstalldir="$osinstalldir/$arch"
		if [ ! -d $archbuilddir ]; then
			configure=1
		fi
		mkdir -p $archbuilddir
		pushd $archbuilddir
			case $os in
				mac)
					vendor="apple"
					sys="darwin"
				;;
				linux)
					vendor="pc"
					sys="linux"
				;;
			esac
			export CC="gcc -arch $arch"
			export CXX="g++ -arch $arch"
			export CFLAGS="$cflags -arch $arch"
			export CXXFLAGS="$cxxflags -arch $arch"
			export LDFLAGS="$ldflags"
			if [ $configure ]; then
				$root/configure --host="$arch-$vendor-$sys" --prefix="$archinstalldir" $configureflags
			fi
			if [ $build ]; then
				make -j 4
				make install
				make check
				if [ "x$os" == "xmac"]; then
					install_name_tool -change "$archinstalldir/lib/libsfw.0.dylib" "@loader_path/libsfw.0.dylib" "$archbuilddir/src/sfw/.libs/libsfw.0.dylib"
					outputlibs="$outputlibs $archbuilddir/src/sfw/.libs/libsfw.0.dylib"
				fi
			fi
		popd
	done
	if [ $build -a "x$os" == "xmac"]; then
		lipo $outputlibs -create -output "$osbuilddir/libsfw.bundle"
	fi
done
