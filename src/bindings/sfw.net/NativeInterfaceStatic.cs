using System;
using System.Runtime.InteropServices;

namespace sfw.net
{
    internal static class NativeInterfaceStatic
    {
        [DllImport("sfw", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr NativeInterface_Create(string path);

        [DllImport("sfw", CallingConvention = CallingConvention.Cdecl)]
        public static extern void NativeInterface_Delete(IntPtr nativeInterface);

        [DllImport("sfw", CallingConvention = CallingConvention.Cdecl)]
        public static extern string NativeInterface_GetError(IntPtr nativeInterface);

        [DllImport("sfw", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool NativeInterface_HasErrored(IntPtr nativeInterface);
   
        [DllImport("sfw")]
        public static extern void NativeInterface_GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize);
    }
}
