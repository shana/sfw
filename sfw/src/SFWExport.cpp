#include "stdafx.h"
#include <iterator>
#include <vector>
#include <algorithm>

#include "../includes/NativeInterface.h"
#include "../includes/SFWExport.h"

NativeInterface* NativeInterface_Create(const char* path)
{
	std::string pathString = path;
	return new NativeInterface(pathString);
}

std::string NativeInterface_getError(NativeInterface* instance)
{
	auto native_interface = static_cast<NativeInterface*>(instance);
	return native_interface->getError();
}

void __stdcall NativeInterface_getEvents(NativeInterface* instance, SFW_Event** events, int* eventsCount)
{
	auto eventVector = instance->getEvents();
	auto count = 0;

	if (eventVector != nullptr)
	{
		*events = new SFW_Event[eventVector->size()];

		for (auto &localEvent : *eventVector)
		{
			auto exportEvent = *events + count;

			exportEvent->type = localEvent->type;

			exportEvent->directory = _strdup(localEvent->directory.c_str());
			exportEvent->fileA = _strdup(localEvent->fileA.c_str());
			
			if(localEvent->fileB.length() == 0)
			{
				exportEvent->fileB = nullptr;
			}
			else
			{
				exportEvent->fileB = _strdup(localEvent->fileB.c_str());
			}
			
			count++;
		}

	}

	*eventsCount = count;

	delete eventVector;
}

bool NativeInterface_hasErrored(NativeInterface* instance)
{
	auto native_interface = static_cast<NativeInterface*>(instance);
	return native_interface->hasErrored();
}

bool NativeInterface_isWatching(NativeInterface* instance)
{
	auto native_interface = static_cast<NativeInterface*>(instance);
	return native_interface->isWatching();
}

void NativeInterface_Delete(NativeInterface* instance)
{
	auto native_interface = static_cast<NativeInterface*>(instance);
	delete native_interface;
}