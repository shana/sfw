platform=AnyCPU

all-local: $(abs_top_builddir)/sfw.net.dll

$(abs_top_builddir)/sfw.net.dll: $(srcdir)/Event.cs $(srcdir)/EventType.cs $(srcdir)/NativeInterface.cs $(srcdir)/NativeInterfaceStatic.cs $(srcdir)/Properties/AssemblyInfo.cs $(srcdir)/sfw.net.csproj
	xbuild $(srcdir)/sfw.net.csproj /property:Platform=$(platform) /property:Configuration=Release /property:SolutionDir=$(abs_top_srcdir) /property:OutputPath=$(abs_top_builddir)

clean-local:
	xbuild $(srcdir)/sfw.net.csproj /property:Platform=$(platform) /property:Configuration=Release /property:SolutionDir=$(abs_top_srcdir) /property:OutputPath=$(abs_top_builddir) /target:Clean
