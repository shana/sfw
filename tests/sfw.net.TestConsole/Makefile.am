if TARGET_32
platform=Win32
else
platform=x64
endif

check-local: $(abs_top_builddir)/sfw.net.TestConsole.exe

$(abs_top_builddir)/sfw.net.TestConsole.exe: $(srcdir)/Program.cs $(srcdir)/Properties/AssemblyInfo.cs $(srcdir)/sfw.net.TestConsole.csproj
	xbuild $(srcdir)/sfw.net.TestConsole.csproj /property:Platform=$(platform) /property:Configuration=Release /property:SolutionDir=$(abs_top_srcdir) /property:OutputPath=$(abs_top_builddir)

clean-local:
	xbuild $(srcdir)/sfw.net.TestConsole.csproj /property:Platform=$(platform) /property:Configuration=Release /property:SolutionDir=$(abs_top_srcdir) /property:OutputPath=$(abs_top_builddir) /target:Clean
