using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using sfw.net;

namespace swf.net.TestConsole
{
    struct TestStruct
    {
        int value;
        string name;
        string name2;
        string name3;
    }

    class Program
    {
        static void Main(string[] args)
        {
            IntPtr events;// = IntPtr.Zero;
            int count;
            
            NativeInterfaceStatic.TestStructMethod(out events, out count);

            List<TestStruct> testStructs = new List<TestStruct>();
            if (count > 0)
            {
                testStructs.Add(Marshal.PtrToStructure<TestStruct>(events));
                count--;

                while (count > 0)
                {
                    events = events + Marshal.SizeOf<TestStruct>();
                    testStructs.Add(Marshal.PtrToStructure<TestStruct>(events));

                    count--;
                }
            }
        }
    }
}
