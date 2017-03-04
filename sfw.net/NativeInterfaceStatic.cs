using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace sfw.net
{
    public static class NativeInterfaceStatic
    {
        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "NativeInterfaceCreateTest")]
        public static extern void NativeInterface_CreateTest();
    }
}
