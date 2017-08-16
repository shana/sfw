using System;
using System.Linq;
using System.Threading;

namespace sfw.net.TestConsole
{
    class Program
    {
        static int Main(string[] args)
        {
            string path = null;

            if (args.Any())
            {
                path = args[0];
            }

            if (string.IsNullOrEmpty(path))
            {
                Console.WriteLine("Missing Path");
                return 1;
            }

            Console.WriteLine("Monitoring Path: " + path);

            using (var nativeInterface = new NativeInterface(path))
            {
                var continueFlag = true;
                while (continueFlag)
                {
                    var events = nativeInterface.GetEvents();
                    if (events.Any())
                    {
                        foreach (Event @event in events)
                        {
                            Console.WriteLine("{0}: {1}", @event.Type, @event.FileA);
                        }
                    }

                    Console.Write("Press any key to continue or 'q' to quit: ");
                    var read = Console.ReadKey();
                    Console.WriteLine(string.Empty);

                    if (read.KeyChar == 'q' || read.KeyChar == 'Q')
                    {
                        continueFlag = false;
                    }
                }
            }

            return 0;
        }
    }
}
