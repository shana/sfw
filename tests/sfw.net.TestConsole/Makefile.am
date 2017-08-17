if TARGET_32
platform=Win32
else
platform=x64
endif

all-local: $(top_builddir)/build/sfw.net.TestConsole.exe

$(top_builddir)/build:
	$(MKDIR_P) $@

$(top_builddir)/build/sfw.net.TestConsole.exe: $(top_builddir)/build Program.cs Properties/AssemblyInfo.cs sfw.net.TestConsole.csproj
	xbuild sfw.net.TestConsole.csproj /property:Platform=$(platform) /property:Configuration=Release /property:SolutionDir=$(top_srcdir) /property:OutputPath=$(top_builddir)/build

clean-local:
	xbuild sfw.net.TestConsole.csproj /property:Platform=$(platform) /property:Configuration=Release /property:SolutionDir=$(top_srcdir) /property:OutputPath=$(top_builddir)/build /target:Clean
