using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Threading;
using sfw.net;

namespace swf.net.TestConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            Debug.WriteLine($@"Output Directory: ""{Environment.CurrentDirectory}""");
            var path = @"C:\Users\Spade\Desktop\ncrunch_report";
            var nativeInterface = NativeInterfaceStatic.NativeInterface_Create(path);

            while (true)
            {
                Thread.Sleep(5000);

                IntPtr events;
                int count;

                NativeInterfaceStatic.NativeInterface_getEvents(nativeInterface, out events, out count);

                var testStructs = new List<Event>();
           
                if (count > 0)
                {
                    testStructs.Add(Marshal.PtrToStructure<Event>(events));
                    count--;

                    while (count > 0)
                    {
                        events = events + Marshal.SizeOf<Event>();
                        testStructs.Add(Marshal.PtrToStructure<Event>(events));

                        count--;
                    }
                }
            }
        }
    }
}
