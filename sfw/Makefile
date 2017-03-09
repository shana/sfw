CXXFLAGS = -std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -fmessage-length=0 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -I ./ -fpic

OBJS =	stdafx.o src/Queue.o src/Lock.o src/NativeInterface.o src/SFWExport.o src/linux/InotifyService.o src/linux/InotifyTree.o src/linux/InotifyEventLoop.o

LIBS = $(OPENPA_STATIC_LIB)

BUILD_OUPUT_FOLDER =	build/linux

TARGET =	$(BUILD_OUPUT_FOLDER)/sfw/sfw.so

PRECOMPILEDHEADER =	stdafx.h.pch

$(TARGET):	$(PRECOMPILEDHEADER) $(OBJS)
	mkdir -p build
	mkdir -p build/linux
	mkdir -p build/linux/sfw
	$(CXX) -std=c++11 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -shared -o $(TARGET) $(OBJS) $(LIBS)

$(PRECOMPILEDHEADER):
	$(CXX) -std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -x c++-header stdafx.h -o $(PRECOMPILEDHEADER)

all:	$(TARGET)

clean:
	rm -rf $(BUILD_OUPUT_FOLDER)
