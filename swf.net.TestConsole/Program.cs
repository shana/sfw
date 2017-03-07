using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
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

                //IntPtr events;// = IntPtr.Zero;

                int count;
                Event[] events;
                NativeInterfaceStatic.NativeInterface_getEvents(nativeInterface, out events, out count);

                if (count > 0)
                {
                    ;
                }
            }
        }
    }
}
