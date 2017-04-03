using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace sfw.net
{
    internal class NativeInterface: IDisposable
    {
        private IntPtr _ptr;

        public NativeInterface(string path)
        {
            _ptr = NativeInterfaceStatic.NativeInterface_Create(path);
        }

        public bool HasErrored()
        {
            return NativeInterfaceStatic.NativeInterface_HasErrored(_ptr);
        }

        public string GetError()
        {
            return NativeInterfaceStatic.NativeInterface_GetError(_ptr);
        }

        public Event[] GetEvents()
        {
            IntPtr eventPtr;
            int count;
            NativeInterfaceStatic.NativeInterface_GetEvents(_ptr, out eventPtr, out count);

            var events = new List<Event>();

            if (count > 0)
            {
                events.Add(Marshal.PtrToStructure<Event>(eventPtr));
                count--;

                while (count > 0)
                {
                    eventPtr = eventPtr + Marshal.SizeOf<Event>();
                    events.Add(Marshal.PtrToStructure<Event>(eventPtr));

                    count--;
                }
            }

            return events.ToArray();
        }

        public void Dispose()
        {
            if (_ptr == IntPtr.Zero)
                return;

            NativeInterfaceStatic.NativeInterface_Delete(_ptr);
            _ptr = IntPtr.Zero;
        }
    }
}