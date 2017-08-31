using System;
using System.Runtime.InteropServices;

namespace sfw.net
{
    interface INativeInterface
    {
        IntPtr Create(string path);
        void Delete(IntPtr nativeInterface);
        string GetError(IntPtr nativeInterface);
        void GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize);
        bool HasError(IntPtr nativeInterface);
    }

    internal static class NativeMethods
    {
        public static bool Is32bit { get { return IntPtr.Size == 4; } }
        public static bool IsWindows { get { return Environment.OSVersion.Platform != PlatformID.Unix && Environment.OSVersion.Platform != PlatformID.MacOSX; } }
        public static bool IsMac { get { return Environment.OSVersion.Platform == PlatformID.MacOSX; } }

        private static INativeInterface nativeInterface;
        private static INativeInterface NativeInterface
        {
            get
            {
                if (nativeInterface == null)
                {
                    if (IsWindows)
                        if (Is32bit)
                            nativeInterface = new Windows32Interface();
                        else
                            nativeInterface = new Windows64Interface();
                    else
                        nativeInterface = new UnixInterface();
                }
                return nativeInterface;
            }
        }

        public static IntPtr Create(string path)
        {
            return NativeInterface.Create(path);
        }

        public static void Delete(IntPtr nativeInterface)
        {
            NativeInterface.Delete(nativeInterface);
        }

        public static string GetError(IntPtr nativeInterface)
        {
            return NativeInterface.GetError(nativeInterface);
        }

        public static bool HasError(IntPtr nativeInterface)
        {
            return NativeInterface.HasError(nativeInterface);
        }

        public static void GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize)
        {
            NativeInterface.GetEvents(nativeInterface, out events, out bufferSize);
        }
    }

    class Windows32Interface : INativeInterface
    {
        public IntPtr Create(string path)
        {
            return NativeCalls.NativeInterface_Create(path);
        }
        public void Delete(IntPtr nativeInterface)
        {
            NativeCalls.NativeInterface_Delete(nativeInterface);
        }
        public string GetError(IntPtr nativeInterface)
        {
            return NativeCalls.NativeInterface_GetError(nativeInterface);
        }
        public bool HasError(IntPtr nativeInterface)
        {
            return NativeCalls.NativeInterface_HasErrored(nativeInterface);
        }

        public void GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize)
        {
            NativeCalls.NativeInterface_GetEvents(nativeInterface, out events, out bufferSize);
        }

        static class NativeCalls
        {
            [DllImport("sfw_x86", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr NativeInterface_Create(string path);

            [DllImport("sfw_x86", CallingConvention = CallingConvention.Cdecl)]
            public static extern void NativeInterface_Delete(IntPtr nativeInterface);

            [DllImport("sfw_x86", CallingConvention = CallingConvention.Cdecl)]
            public static extern string NativeInterface_GetError(IntPtr nativeInterface);

            [DllImport("sfw_x86", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool NativeInterface_HasErrored(IntPtr nativeInterface);

            [DllImport("sfw_x86", CallingConvention = CallingConvention.Cdecl)]
            public static extern void NativeInterface_GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize);
        }
    }

    class Windows64Interface : INativeInterface
    {
        public IntPtr Create(string path)
        {
            return NativeCalls.NativeInterface_Create(path);
        }
        public void Delete(IntPtr nativeInterface)
        {
            NativeCalls.NativeInterface_Delete(nativeInterface);
        }
        public string GetError(IntPtr nativeInterface)
        {
            return NativeCalls.NativeInterface_GetError(nativeInterface);
        }
        public bool HasError(IntPtr nativeInterface)
        {
            return NativeCalls.NativeInterface_HasErrored(nativeInterface);
        }

        public void GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize)
        {
            NativeCalls.NativeInterface_GetEvents(nativeInterface, out events, out bufferSize);
        }

        static class NativeCalls
        {
            [DllImport("sfw_x64", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr NativeInterface_Create(string path);

            [DllImport("sfw_x64", CallingConvention = CallingConvention.Cdecl)]
            public static extern void NativeInterface_Delete(IntPtr nativeInterface);

            [DllImport("sfw_x64", CallingConvention = CallingConvention.Cdecl)]
            public static extern string NativeInterface_GetError(IntPtr nativeInterface);

            [DllImport("sfw_x64", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool NativeInterface_HasErrored(IntPtr nativeInterface);

            [DllImport("sfw_x64", CallingConvention = CallingConvention.Cdecl)]
            public static extern void NativeInterface_GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize);
        }
    }

    class UnixInterface : INativeInterface
    {
        public IntPtr Create(string path)
        {
            return NativeCalls.NativeInterface_Create(path);
        }
        public void Delete(IntPtr nativeInterface)
        {
            NativeCalls.NativeInterface_Delete(nativeInterface);
        }
        public string GetError(IntPtr nativeInterface)
        {
            return NativeCalls.NativeInterface_GetError(nativeInterface);
        }
        public bool HasError(IntPtr nativeInterface)
        {
            return NativeCalls.NativeInterface_HasErrored(nativeInterface);
        }

        public void GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize)
        {
            NativeCalls.NativeInterface_GetEvents(nativeInterface, out events, out bufferSize);
        }

        static class NativeCalls
        {
            [DllImport("libsfw", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr NativeInterface_Create(string path);

            [DllImport("libsfw", CallingConvention = CallingConvention.Cdecl)]
            public static extern void NativeInterface_Delete(IntPtr nativeInterface);

            [DllImport("libsfw", CallingConvention = CallingConvention.Cdecl)]
            public static extern string NativeInterface_GetError(IntPtr nativeInterface);

            [DllImport("libsfw", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool NativeInterface_HasErrored(IntPtr nativeInterface);

            [DllImport("libsfw", CallingConvention = CallingConvention.Cdecl)]
            public static extern void NativeInterface_GetEvents(IntPtr nativeInterface, out IntPtr events, out int bufferSize);
        }
    }
}
