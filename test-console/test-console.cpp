// test-console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "../sfw/includes/NativeInterface.h"

int main()
{
//	auto path = "C:\\Users\\Spade\\Desktop\\ncrunch_report";
//	auto native_interface = NativeInterface_Create(path);
//
//	auto continueFlag = true;
//	while (continueFlag)
//	{
//		auto const bufferSize = 2;
//		auto buffer = new EventSimple[bufferSize];
//
//		auto eventCount = NativeInterface_getEvents(native_interface, buffer, bufferSize);
//		for (auto i = 0; i < eventCount; i++)
//		{
//			auto evt = buffer[i];
//			std::cout << "Change: ";
//			switch (evt.type)
//			{
//			case CREATED:
//				std::cout << "Created: ";
//				break;
//
//			case DELETED:
//				std::cout << "Deleted: ";
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
//			std::cout << evt.fileA << std::endl;
//		}
//
//		std::cout << "Press any key or 'q' to quit: ";
//		auto inputChar = std::cin.get();
//		if (inputChar == 'q' || inputChar == 'Q')
//		{
//			continueFlag = false;
//		}
//	}
//
//	NativeInterface_Delete(native_interface);

	int stackInt = 3;
	auto testStruct = new TestStruct*[0];
	auto testStructCount = new int;

	TestStructMethod(reinterpret_cast<void**>(testStruct), testStructCount);

	return 0;
}
