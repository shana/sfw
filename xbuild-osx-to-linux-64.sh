#!/bin/sh
BASE="/usr/local/gcc-4.8.1-for-linux64"
PREFIX="x86_64-pc-linux"
SYSROOT="${BASE}/${PREFIX}"
for tool in addr2line ar as c++ c++filt cpp elfedit g++ gcc ar nm ranlib gcov gprof ld ld.bfd nm objcopy objdump ranlib readelf size strings strip; do
	t=`echo $tool | tr /a-z/ /A-Z/ | tr /+/ /X/`
	export ${t}=${BASE}/bin/${PREFIX}-${tool}
done
export PATH="${SYSROOT}/bin:${PATH}"
export PKG_CONFIG_PATH=
export CFLAGS="${CFLAGS} "
export CPPFLAGS="${CPPFLAGS} -I${SYSROOT}/include"
export LDFLAGS="${LDLAGS} -L${SYSROOT}/lib"
export CC="${GCC}"
export CXX="${GXX}"
export GCC=
export GXX=
env

./build.sh -os linux -arch x86_64