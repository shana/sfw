CXXFLAGS =	-std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -fmessage-length=0 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -I sfw/ -fpic

OBJS =		sfw/stdafx.o sfw/src/Queue.o sfw/src/Lock.o sfw/src/NativeInterface.o sfw/src/SFWExport.o sfw/src/linux/InotifyService.o sfw/src/linux/InotifyTree.o sfw/src/linux/InotifyEventLoop.o

LIBS =

TARGET =	build/linux/sfw/sfw.so

PRECOMPILEDHEADER =	sfw/stdafx.h.pch

OPENPA_STATIC_OUTPUT_FOLDER =	openpa/out/

OPENPA_STATIC_LIB =	build/linux/openpa/libopenpa.a

$(TARGET):	$(OPENPA_STATIC_LIB) $(PRECOMPILEDHEADER) $(OBJS)
	mkdir -p build
	mkdir -p build/linux
	mkdir -p build/linux/sfw
	$(CXX) -std=c++11 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -shared -o $(TARGET) $(OBJS) $(LIBS)

$(PRECOMPILEDHEADER):
	$(CXX) -std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -x c++-header sfw/stdafx.h -o $(PRECOMPILEDHEADER)

$(OPENPA_STATIC_LIB):
	mkdir -p build
	mkdir -p build/linux
	mkdir -p build/linux/openpa
	$(MAKE) -C openpa/ all
	cp -f $(OPENPA_STATIC_OUTPUT_FOLDER)Default/obj.target/libopenpa.a $(OPENPA_STATIC_LIB)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(PRECOMPILEDHEADER)
	rm -rf $(OPENPA_STATIC_OUTPUT_FOLDER)
