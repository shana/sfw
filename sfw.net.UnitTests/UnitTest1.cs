﻿using System;
using System.Diagnostics;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace sfw.net.UnitTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Debug.WriteLine($@"Output Directory: ""{Environment.CurrentDirectory}""");
            var path = "C:\\Users\\StanleyGoldman\\Desktop\\ncrunch_report";
            var nativeInterface = NativeInterfaceStatic.NativeInterface_Create(path);

            while (true)
            {
                Thread.Sleep(5000);
                var nativeInterfaceGetEvents = NativeInterfaceStatic.NativeInterface_getEvents(nativeInterface);
            }



//            NativeInterfaceStatic.NativeInterface_Delete(nativeInterface);
        }
    }
}
