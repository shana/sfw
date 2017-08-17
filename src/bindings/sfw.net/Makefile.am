if TARGET_32
platform=Win32
else
platform=x64
endif

all-local: $(top_builddir)/build/sfw.net.dll

$(top_builddir)/build:
	$(MKDIR_P) $@

$(top_builddir)/build/sfw.net.dll: $(top_builddir)/build Event.cs EventType.cs NativeInterface.cs NativeInterfaceStatic.cs Properties/AssemblyInfo.cs sfw.net.csproj
	xbuild sfw.net.csproj /property:Platform=$(platform) /property:Configuration=Release /property:SolutionDir=$(top_srcdir) /property:OutputPath=$(top_builddir)/build

clean-local:
	xbuild sfw.net.csproj /property:Platform=$(platform) /property:Configuration=Release /property:SolutionDir=$(top_srcdir) /property:OutputPath=$(top_builddir)/build /target:Clean
