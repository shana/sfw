// test-console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../sfw/includes/NativeInterface.h"
#include <iostream>
#include <vector>

int main()
{
	auto path = "C:\\Users\\StanleyGoldman\\Desktop\\ncrunch_report";
	NativeInterface f(path);

	auto continueFlag = true;
	while (continueFlag)
	{
		auto fileEvents = f.getEvents();
		if (fileEvents == nullptr || fileEvents->size() <= 0)
		{
			std::cout << "No events." << std::endl;
		}
		else
		{
			for (std::vector<Event*>::iterator fileEvent = fileEvents->begin(); fileEvent != fileEvents->end(); ++fileEvent)
			{
				auto evt = *fileEvent;
				std::cout << "Change: ";
				switch (evt->type)
				{
				case DELETED:
					std::cout << "Deleted: ";
					break;

				case CREATED:
					std::cout << "Created: ";
					break;

				case MODIFIED:
					std::cout << "Modified: ";
					break;

				case RENAMED:
					std::cout << "Renamed: ";
					break;
				}

				std::cout << evt->fileA << std::endl;
			}
		}

		std::cout << "Press any key or 'q' to quit: ";
		auto inputChar = std::cin.get();
		if (inputChar == 'q' || inputChar == 'Q')
		{
			continueFlag = false;
		}
	}

	return 0;
}

