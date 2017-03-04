#include "stdafx.h"
#include "../includes/NativeInterface.h"

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

std::vector<Event *> *NativeInterface::getEvents() {
  if (mQueue.count() == 0) {
    return NULL;
  }

  int count = mQueue.count();
  std::vector<Event *> *events = new std::vector<Event *>;
  events->reserve(count);
  for (int i = 0; i < count; ++i) {
    events->push_back(mQueue.dequeue());
  }

  return events;
}

bool NativeInterface::hasErrored() {
  return ((SERVICE *)mNativeInterface)->hasErrored();
}

bool NativeInterface::isWatching() {
  return ((SERVICE *)mNativeInterface)->isWatching();
}

void NativeInterfaceCreateTest()
{
	auto pathString = "C:\\Users\\StanleyGoldman\\Desktop\\ncrunch_report";
	NativeInterface f(pathString);
}

NativeInterface* NativeInterface_Create(const char* path)
{
	std::string pathString = path;
	return new NativeInterface(pathString);
}

std::string NativeInterface_getError(NativeInterface* pNativeInterface) { return pNativeInterface->getError(); }

std::vector<Event*>* NativeInterface_getEvents(NativeInterface* pNativeInterface) { return pNativeInterface->getEvents(); }

bool NativeInterface_hasErrored(NativeInterface* pNativeInterface) { return pNativeInterface->hasErrored(); }

bool NativeInterface_isWatching(NativeInterface* pNativeInterface) { return pNativeInterface->isWatching(); }

void NativeInterface_Delete(NativeInterface* pNativeInterface) { delete pNativeInterface; }