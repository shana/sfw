CXXFLAGS =	-std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -fmessage-length=0 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -I sfw/ -fpic

SFW_OBJS =	sfw/stdafx.o sfw/src/Queue.o sfw/src/Lock.o sfw/src/NativeInterface.o sfw/src/SFWExport.o sfw/src/linux/InotifyService.o sfw/src/linux/InotifyTree.o sfw/src/linux/InotifyEventLoop.o

TEST_CONSOLE_OBJS =	test-console/stdafx.o test-console/test-console.o

LIBS =

BUILD_OUPUT_FOLDER =	build/linux/

SFW_SHARED_LIB =	$(BUILD_OUPUT_FOLDER)sfw/sfw.so

SFW_PRECOMPILEDHEADER =	sfw/stdafx.h.pch

TEST_CONSOLE_PRECOMPILEDHEADER =	test-console/stdafx.h.pch

TEST_CONSOLE =	$(BUILD_OUPUT_FOLDER)test-console/test-console

OPENPA_STATIC_OUTPUT_FOLDER =	openpa/out/

OPENPA_STATIC_LIB =	$(BUILD_OUPUT_FOLDER)openpa/libopenpa.a

$(SFW_SHARED_LIB):	$(OPENPA_STATIC_LIB) $(SFW_PRECOMPILEDHEADER) $(SFW_OBJS)
	mkdir -p build
	mkdir -p build/linux
	mkdir -p build/linux/sfw
	$(CXX) -std=c++11 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -shared -o $(SFW_SHARED_LIB) $(SFW_OBJS) $(LIBS)

$(SFW_PRECOMPILEDHEADER):
	$(CXX) -std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -x c++-header sfw/stdafx.h -o $(SFW_PRECOMPILEDHEADER)

$(OPENPA_STATIC_LIB):
	mkdir -p build
	mkdir -p build/linux
	mkdir -p build/linux/openpa
	$(MAKE) -C openpa/ all
	cp -f $(OPENPA_STATIC_OUTPUT_FOLDER)Default/obj.target/libopenpa.a $(OPENPA_STATIC_LIB)

$(TEST_CONSOLE_PRECOMPILEDHEADER):
	$(CXX) -std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -x c++-header sfw/stdafx.h -o $(TEST_CONSOLE_PRECOMPILEDHEADER)

$(TEST_CONSOLE):	$(SFW_SHARED_LIB) $(TEST_CONSOLE_PRECOMPILEDHEADER) $(SFW_OBJS)
	mkdir -p build
	mkdir -p build/linux
	mkdir -p build/linux/sfw
	$(CXX) -std=c++11 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -shared -o $(SFW_SHARED_LIB) $(TEST_CONSOLE_OBJS) $(LIBS)

all:	$(SFW_SHARED_LIB)

clean:
	rm -f $(SFW_OBJS) $(SFW_PRECOMPILEDHEADER) $(TEST_CONSOLE_PRECOMPILEDHEADER)
	rm -rf $(OPENPA_STATIC_OUTPUT_FOLDER) $(BUILD_OUPUT_FOLDER)
