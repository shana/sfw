using System;
using System.Runtime.InteropServices;

namespace sfw.net
{
    internal static class NativeInterfaceStatic
    {
        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr NativeInterface_Create(string path);

        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void NativeInterface_Delete(IntPtr nativeInterface);

        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern string NativeInterface_getError(IntPtr nativeInterface);

        [DllImport("sfw.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool NativeInterface_hasErrored(IntPtr nativeInterface);
   
        [DllImport("sfw.dll")]
        public static extern void NativeInterface_getEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize);
    }
}
