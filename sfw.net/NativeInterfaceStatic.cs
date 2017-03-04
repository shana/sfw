using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace sfw.net
{
    enum EventType
    {
        CREATED = 0,
        DELETED = 1,
        MODIFIED = 2,
        RENAMED = 3
    };

    struct Event
    {
        EventType type;
        string directory;
        string fileA;
        string fileB;
    };

    internal static class NativeInterfaceStatic
    {
        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "?NativeInterface_Create@@YAPAXPBD@Z")]
        public static extern IntPtr NativeInterface_Create(string path);

        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "?NativeInterface_Delete@@YAPAXPBD@Z")]
        public static extern void NativeInterface_Delete(IntPtr nativeInterface);

        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "?NativeInterface_getError@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAX@Z")]
        public static extern string NativeInterface_getError(IntPtr nativeInterface);
   
        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "?NativeInterface_getEvents@@YAPAV?$vector@PAUEvent@@V?$allocator@PAUEvent@@@std@@@std@@PAX@Z")]
        public static extern IList NativeInterface_getEvents(IntPtr nativeInterface);
    }
}
