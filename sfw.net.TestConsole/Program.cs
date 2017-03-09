using System.Linq;
using System.Threading;

namespace sfw.net.TestConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var nativeInterface = new NativeInterface(@"C:\Users\Spade\Desktop\ncrunch_report"))
            {
                while (true)
                {
                    Thread.Sleep(5000);

                    var events = nativeInterface.GetEvents();
                    if (Enumerable.Any<sfw.net.Event>(events))
                    {
                        ;
                    }
                }
            }
        }
    }
}
