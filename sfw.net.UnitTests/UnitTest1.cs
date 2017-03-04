using System;
using System.Diagnostics;
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
            NativeInterfaceStatic.NativeInterface_CreateTest();
        }
    }
}
