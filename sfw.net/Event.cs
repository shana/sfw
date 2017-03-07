using System.Runtime.InteropServices;

namespace sfw.net
{
    [StructLayout(LayoutKind.Sequential)]
    struct Event
    {
        EventType type;
        string directory;
        string fileA;
        string fileB;
    };
}