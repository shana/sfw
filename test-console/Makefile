CXXFLAGS =	-std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -fmessage-length=0 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -I ./

OBJS =	stdafx.o test-console.o

LIBS = $(OUTPUT_SFW_LIB)

BUILD_OUPUT_FOLDER =	build/linux

TARGET =	$(BUILD_OUPUT_FOLDER)/test-console

PRECOMPILEDHEADER =	stdafx.h.pch

$(PRECOMPILEDHEADER):
	$(CXX) -std=c++11 -O2 -g -Wall -Wno-unknown-pragmas -x c++-header stdafx.h -o $(PRECOMPILEDHEADER)

$(TARGET):	$(PRECOMPILEDHEADER) $(OBJS)
	mkdir -p build
	mkdir -p build/linux
	$(CXX) -std=c++11 -DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1 -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -rf $(BUILD_OUPUT_FOLDER) $(OBJS)
