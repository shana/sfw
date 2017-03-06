#ifndef NSFW_NATIVE_INTERFACE_H
#define NSFW_NATIVE_INTERFACE_H

#include "Queue.h"
#include <vector>
#include "ExportHeader.h"

class NativeInterface {
public:
  NativeInterface(std::string path);

  std::string getError();
  std::vector<Event*>* getEvents(int bufferSize);
  std::vector<Event*>* getEvents();
  bool hasErrored();
  bool isWatching();

  ~NativeInterface();
private:
EventQueue mQueue;
  void *mNativeInterface;
};

struct EventSimple {
	EventType type;
	char* directory;
	char* fileA;
	char* fileB;
};

extern "C" SFW_EXPORT_API void* NativeInterface_Create(const char* path);

extern "C" SFW_EXPORT_API std::string NativeInterface_getError(void* pNativeInterface);

extern "C" SFW_EXPORT_API void NativeInterface_getEvents(void* pNativeInterface, EventSimple** events, int* eventsCount);

extern "C" SFW_EXPORT_API bool NativeInterface_hasErrored(void* pNativeInterface);

extern "C" SFW_EXPORT_API bool NativeInterface_isWatching(void* pNativeInterface);

extern "C" SFW_EXPORT_API void NativeInterface_Delete(void* pNativeInterface);

#endif
