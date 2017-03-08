BUILD_OUPUT_FOLDER =	build/linux/

OPENPA_STATIC_OUTPUT_FOLDER =	openpa/out/

OPENPA_STATIC_LIB =	$(BUILD_OUPUT_FOLDER)openpa/libopenpa.a

$(OPENPA_STATIC_LIB):
	mkdir -p build
	mkdir -p build/linux
	mkdir -p build/linux/openpa
	$(MAKE) -C openpa/ all
	cp -f $(OPENPA_STATIC_OUTPUT_FOLDER)Default/obj.target/libopenpa.a $(OPENPA_STATIC_LIB)

all:	$(OPENPA_STATIC_LIB)

clean:
	rm -rf $(OPENPA_STATIC_OUTPUT_FOLDER) $(BUILD_OUPUT_FOLDER)
