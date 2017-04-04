// test-console.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "SFWExport.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Missing path" << std::endl;
		return 1;
	}

	std::cout << "Monitoring Path: " << argv[1] << std::endl;

	auto native_interface = NativeInterface_Create(argv[1]);

	auto continueFlag = true;
	while (continueFlag)
	{
		auto const bufferSize = 2;
		auto buffer = new SFW_Event[bufferSize];

		int eventCount;
		NativeInterface_GetEvents(native_interface, &buffer, &eventCount);
		for (auto i = 0; i < eventCount; i++)
		{
			auto evt = buffer[i];
			std::cout << "Change: ";
			switch (evt.type)
			{
			case CREATED:
				std::cout << "Created: ";
				break;

			case DELETED:
				std::cout << "Deleted: ";
				break;

			case MODIFIED:
				std::cout << "Modified: ";
				break;

			case RENAMED:
				std::cout << "Renamed: ";
				break;
			}

			std::cout << evt.fileA << std::endl;
		}

		std::cout << "Press any key or 'q' to quit: ";
		auto inputChar = std::cin.get();
		if (inputChar == 'q' || inputChar == 'Q')
		{
			continueFlag = false;
		}
	}

	NativeInterface_Delete(native_interface);

	return 0;
}
