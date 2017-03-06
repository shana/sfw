#include "stdafx.h"
#include "../includes/NativeInterface.h"
#include <iterator>
#include <vector>
#include <algorithm>

#if defined(_WIN32)
#define SERVICE ReadLoop
#include "../includes/win32/ReadLoop.h"
#elif defined(__APPLE_CC__) || defined(BSD)
#define SERVICE FSEventsService
#include "../includes/osx/FSEventsService.h"
#elif defined(__linux__)
#define SERVICE InotifyService
#include "../includes/linux/InotifyService.h"
#endif

NativeInterface::NativeInterface(std::string path) {
	mNativeInterface = new SERVICE(mQueue, path);
}

NativeInterface::~NativeInterface() {
	delete (SERVICE *)mNativeInterface;
}

std::string NativeInterface::getError() {
	return ((SERVICE *)mNativeInterface)->getError();
}

std::vector<Event*>* NativeInterface::getEvents(int bufferSize)
{
	if (mQueue.count() == 0) {
		return NULL;
	}

	int count;
	if (bufferSize <= 0)
	{
		count = mQueue.count();
	}
	else
	{
		count = min(mQueue.count(), bufferSize);
	}

	std::vector<Event *> *events = new std::vector<Event *>;
	events->reserve(count);
	for (int i = 0; i < count; ++i) {
		events->push_back(mQueue.dequeue());
	}

	return events;
}

std::vector<Event*>* NativeInterface::getEvents() {
	return this->getEvents(-1);
}

bool NativeInterface::hasErrored() {
	return ((SERVICE *)mNativeInterface)->hasErrored();
}

bool NativeInterface::isWatching() {
	return ((SERVICE *)mNativeInterface)->isWatching();
}

void* NativeInterface_Create(const char* path)
{
	std::string pathString = path;
	return new NativeInterface(pathString);
}

std::string NativeInterface_getError(void* ptr)
{
	auto native_interface = static_cast<NativeInterface*>(ptr);
	return native_interface->getError();
}

int NativeInterface_getEvents(void* ptr, Event* buffer, int bufferSize)
{
	auto native_interface = static_cast<NativeInterface*>(ptr);
	
	auto events = native_interface->getEvents(bufferSize);
	auto count = 0;

	if(events != nullptr)
	{
		for (auto & event : *events) {
			 auto eventCopy = *event;
			 buffer[count++] = eventCopy;
		}
	}

	delete events;

	return count;
}

Event dereferenceEvent(Event* event)
{
	return *event;
}

bool NativeInterface_hasErrored(void* ptr)
{
	auto native_interface = static_cast<NativeInterface*>(ptr);
	return native_interface->hasErrored();
}

bool NativeInterface_isWatching(void* ptr)
{
	auto native_interface = static_cast<NativeInterface*>(ptr);
	return native_interface->isWatching();
}

void NativeInterface_Delete(void* ptr)
{
	auto native_interface = static_cast<NativeInterface*>(ptr);
	delete native_interface;
}