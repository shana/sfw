#if _WIN32
#include "stdafx.h"
#endif

#include "../includes/NativeInterface.h"
#include <stdio.h>
#include <iterator>
#include <vector>
#include <algorithm>

#if defined(_WIN32)
#define SERVICE ReadLoop
#include "../includes/win32/ReadLoop.h"
#include <windows.h>
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
		count = std::min(mQueue.count(), bufferSize);
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
