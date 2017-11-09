# SFW - Sentinel File Watcher, a port of NSFW without the N bits

## Windows

- Open sfw.sln and build

## Mac

- Run `./build.sh -os mac -arch "i386 x86_64"` (or whatever arch you need)

## Linux

- Run `./build.sh -os linux -arch "i386 x86_64"` (or whatever arch you need)

## Cross-compiling to linux from mac (64bit only)

- Install the cross compiler at http://crossgcc.rts-software.org/doku.php?id=compiling_for_linux
- Run `./xbuild-osx-to-linux-64.sh`
