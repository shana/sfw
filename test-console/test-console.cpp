// test-console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "../sfw/includes/NativeInterface.h"

int main()
{
	auto path = "C:\\Users\\Spade\\Desktop\\ncrunch_report";
	auto native_interface = NativeInterface_Create(path);

	auto continueFlag = true;
	while (continueFlag)
	{
		Event* events;
		int eventCount = 0;

//		NativeInterface_getEvents(native_interface, eventCount, events);
//		
//		std::vector<Event*> fileEvents;
//		
//		if (eventCount > 0)
//		{
//			fileEvents.assign(eventCount, events);
//		}
//
//		for (auto fileEvent = fileEvents.begin(); fileEvent != fileEvents.end(); ++fileEvent)
//		{
//			auto evt = *fileEvent;
//			std::cout << "Change: ";
//			switch (evt->type)
//			{
//			case DELETED:
//				std::cout << "Deleted: ";
//				break;
//
//			case CREATED:
//				std::cout << "Created: ";
//				break;
//
//			case MODIFIED:
//				std::cout << "Modified: ";
//				break;
//
//			case RENAMED:
//				std::cout << "Renamed: ";
//				break;
//			}
//
//			std::cout << evt->fileA << std::endl;
//		}

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
