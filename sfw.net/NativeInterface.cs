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
            return NativeInterfaceStatic.NativeInterface_hasErrored(_ptr);
        }

        public string GetError()
        {
            return NativeInterfaceStatic.NativeInterface_getError(_ptr);
        }

        public Event[] GetEvents()
        {
            IntPtr eventPtr;
            int count;
            NativeInterfaceStatic.NativeInterface_getEvents(_ptr, out eventPtr, out count);

            var events = new List<Event>();

            if (count > 0)
            {
                events.Add((Event) Marshal.PtrToStructure(eventPtr, typeof(Event)));
                count--;

                while (count > 0)
                {
                    eventPtr = new IntPtr(eventPtr.ToInt64() + Marshal.SizeOf(typeof(Event)));
                    events.Add((Event) Marshal.PtrToStructure(eventPtr, typeof(Event)));

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