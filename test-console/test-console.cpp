// test-console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../sfw/includes/sfw_exports.h"
#include <iostream>
#include <vector>

int main()
{
	auto path = "C:\\Users\\StanleyGoldman\\Desktop\\ncrunch_report";
	auto native_interface = NativeInterface_Create(path);

	auto continueFlag = true;
	while (continueFlag)
	{
//		auto fileEvents = NativeInterface_getEvents(native_interface);
//		if (fileEvents == nullptr || fileEvents->size() <= 0)
//		{
//			std::cout << "No events." << std::endl;
//		}
//		else
//		{
//			for (auto fileEvent = fileEvents->begin(); fileEvent != fileEvents->end(); ++fileEvent)
//			{
//				auto evt = *fileEvent;
//				std::cout << "Change: ";
//				switch (evt->type)
//				{
//				case DELETED:
//					std::cout << "Deleted: ";
//					break;
//
//				case CREATED:
//					std::cout << "Created: ";
//					break;
//
//				case MODIFIED:
//					std::cout << "Modified: ";
//					break;
//
//				case RENAMED:
//					std::cout << "Renamed: ";
//					break;
//				}
//
//				std::cout << evt->fileA << std::endl;
//			}
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

