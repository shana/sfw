#!/bin/sh -ex
NOCONFIGURE=1 ./autogen.sh
OS="win mac linux"
ARCH="x86 x64"
underscore=_
for os in $OS; do
	for arch in $ARCH; do
		builddir=build/$os/$arch
		mkdir -p $builddir
		pushd $builddir
			case $arch in
				x86)
					targetcpu="i386"
				;;
				*)
					targetcpu="x86_64"
				;;
			esac
			case $os in
				win)
					targetos="pc-windows"
				;;
				mac)
					targetos="apple-darwin"
				;;
				linux)
					targetos="linux"
				;;
			esac
			../../../configure --target="$targetcpu-$targetos" || true
			make || true
		popd
	done
done