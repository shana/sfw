# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := openpa
DEFS_Default := \
	'-DOPA_HAVE_GCC_INTRINSIC_ATOMICS=1' \
	'-DHAVE_STDDEF_H=1' \
	'-DHAVE_STDLIB_H=1' \
	'-DHAVE_UNISTD_H=1' \
	'-DOPA_SIZEOF_VOID_P=8'

# Flags passed to all source files.
CFLAGS_Default :=

# Flags passed to only C files.
CFLAGS_C_Default :=

# Flags passed to only C++ files.
CFLAGS_CC_Default :=

INCS_Default := \
	-Isrc/primitves \
	-Isrc

OBJS := \
	$(obj).target/$(TARGET)/src/opa_primitives.o \
	$(obj).target/$(TARGET)/src/opa_queue.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Default :=

LIBS :=

$(obj).target/libopenpa.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/libopenpa.a: LIBS := $(LIBS)
$(obj).target/libopenpa.a: TOOLSET := $(TOOLSET)
$(obj).target/libopenpa.a: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,alink_thin)

all_deps += $(obj).target/libopenpa.a
# Add target alias
.PHONY: openpa
openpa: $(obj).target/libopenpa.a

# Add target alias to "all" target.
.PHONY: all
all: openpa

