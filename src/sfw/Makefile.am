lib_LTLIBRARIES = sfw.la

includes = $(addprefix -I$(top_srcdir)/, $(INCLUDE_PATHS))

if TARGET_WIN
endif

if TARGET_LINUX
os_sources = \
	src/linux/InotifyEventLoop.cpp \
	src/linux/InotifyService.cpp \
	src/linux/InotifyTree.cpp \
	includes/linux/InotifyEventLoop.h \
	includes/linux/InotifyService.h \
	includes/linux/InotifyTree.h
endif

if TARGET_MAC
os_sources = \
	src/osx/FSEventsService.cpp \
	src/osx/RunLoop.cpp \
	includes/osx/FSEventsService.h \
	includes/osx/RunLoop.h
endif

sfw_la_SOURCES = \
	../config.h \
	src/Lock.cpp \
	src/Queue.cpp \
	src/NativeInterface.cpp \
	src/SFWExport.cpp \
	includes/Lock.h \
	includes/Queue.h \
	includes/NativeInterface.h \
	includes/SFWExport.h \
	$(os_sources)

sfw_la_CPPFLAGS = $(CPPFLAGS) $(includes)

sfw_la_LIBADD = $(top_builddir)/src/openpa/libopenpa.la
sfw_la_LDFLAGS = $(LDFLAGS) -module -no-undefined -framework CoreServices
