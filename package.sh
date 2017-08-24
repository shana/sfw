#!/bin/sh -ex
NOCONFIGURE=1 ./autogen.sh
pushd m4
patch -f<libtool.patch
popd
OS="mac"
ARCH="i386 x86_64"
root=`pwd`
builddir=$root/build

sdkpath="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk"
sdkversion="10.9"
c_flags="$CFLAGS -isysroot $sdkpath -mmacosx-version-min=$sdkversion"
cxx_flags="$CXXFLAGS -O2 -g -stdlib=libc++ -isysroot $sdkpath -mmacosx-version-min=$sdkversion"
ld_flags="$LDFLAGS"
prefix="/loader_path/libsfw.0.dylib/install"

for os in $OS; do
	for arch in $ARCH; do
		archbuilddir="$builddir/$os/$arch"
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
			export CFLAGS="$c_flags -arch $arch"
			export CXXFLAGS="$cxx_flags -arch $arch"
			export LDFLAGS="$ld_flags"
			$root/configure --host="$arch-$vendor-$sys" --prefix="$prefix"
			make -j 4
			make check
		popd
	done
done
install_name_tool -change "$prefix/lib/libsfw.0.dylib" "@loader_path/libsfw.0.dylib" "$builddir/mac/i386/src/sfw/.libs/libsfw.0.dylib"
install_name_tool -change "$prefix/lib/libsfw.0.dylib" "@loader_path/libsfw.0.dylib" "$builddir/mac/x86_64/src/sfw/.libs/libsfw.0.dylib"
lipo $builddir/mac/i386/src/sfw/.libs/libsfw.0.dylib $builddir/mac/x86_64/src/sfw/.libs/libsfw.0.dylib -create -output $root/build/mac/libsfw.bundle