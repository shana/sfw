check_PROGRAMS = test-console

includes = $(addprefix -I$(top_srcdir)/, $(INCLUDE_PATHS))
test_console_CPPFLAGS = $(CPPFLAGS) $(includes)

AM_DEFAULT_SOURCE_EXT = .cpp

ifdef TARGET_MAC
libsfw.bundle: $(top_builddir)/src/sfw/.libs/sfw.0.so
	$(LN_S) $< $@

test-console.o: libsfw.bundle
endif

ifdef TARGET_LINUX
libsfw.so: $(top_builddir)/src/sfw/.libs/libsfw.0.so
	$(LN_S) $< $@

test-console.o: libsfw.so
endif