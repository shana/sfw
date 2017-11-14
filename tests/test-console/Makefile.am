check_PROGRAMS = test-console

includes = $(addprefix -I$(top_srcdir)/, $(INCLUDE_PATHS))
test_console_CPPFLAGS = $(CPPFLAGS) $(includes)

test_console_LDFLAGS = $(LDFLAGS) -pthread
if TARGET_MAC
test_console_LDFLAGS += -framework CoreFoundation -framework CoreServices
endif

test_console_LDADD = $(top_builddir)/src/sfw/libsfw.la

AM_DEFAULT_SOURCE_EXT = .cpp

if TARGET_MAC
libsfw.dylib: $(top_builddir)/src/sfw/.libs/libsfw.0.dylib
	$(LN_S) -f $< $@

check-local: libsfw.dylib
clean-local:
	$(RM) libsfw.dylib
endif

if TARGET_LINUX
libsfw.so: $(top_builddir)/src/sfw/.libs/libsfw.so
	$(LN_S) -f $< $@

check-local: libsfw.so
clean-local:
	$(RM) libsfw.so
endif