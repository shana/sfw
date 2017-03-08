CXXFLAGS =	-std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -fmessage-length=0 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -I sfw/

OBJS =		sfw/stdafx.o sfw/src/Queue.o sfw/src/Lock.o sfw/src/NativeInterface.o sfw/src/SFWExport.o sfw/src/linux/InotifyService.o sfw/src/linux/InotifyTree.o sfw/src/linux/InotifyEventLoop.o

LIBS =

TARGET =	build/linux/sfw

PRECOMPILEDHEADER =	sfw/stdafx.h.pch

$(TARGET):	$(PRECOMPILEDHEADER) $(OBJS) openpa
	$(CXX) -std=c++11 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -o $(TARGET) $(OBJS) $(LIBS)

sfw/stdafx.h.pch:
	$(CXX) -std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -x c++-header sfw/stdafx.h -o $(PRECOMPILEDHEADER)

openpa:
	$(MAKE) -C openpa/ all

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(PRECOMPILEDHEADER)
