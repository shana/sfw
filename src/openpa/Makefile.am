lib_LTLIBRARIES = libopenpa.la

if TARGET_UNIX
os_sources=src/primitives/opa_gcc_intrinsics.h
else
os_sources=src/primitives/opa_nt_intrinsics.h
endif

libopenpa_la_SOURCES = \
	src/primitives/opa_emulated.h \
	src/opa_config.h \
	src/opa_primitives.h \
	src/opa_primitives.c \
	src/opa_util.h \
	src/opa_queue.h \
	src/opa_queue.c \
	$(os_sources)

libopenpa_la_LDFLAGS = -static
