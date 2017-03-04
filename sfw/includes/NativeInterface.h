#ifndef NSFW_NATIVE_INTERFACE_H
#define NSFW_NATIVE_INTERFACE_H

#include "Queue.h"
#include "sfw_exports.h"
#include <vector>

class SFW_EXPORT_API NativeInterface {
public:
  NativeInterface(std::string path);

  std::string getError();
  std::vector<Event *> *getEvents();
  bool hasErrored();
  bool isWatching();

  ~NativeInterface();
private:
  EventQueue mQueue;
  void *mNativeInterface;
};

SFW_EXPORT_API void NativeInterfaceCreateTest();

SFW_EXPORT_API NativeInterface* NativeInterface_Create(const char* path);

SFW_EXPORT_API std::string NativeInterface_getError(NativeInterface* pNativeInterface);

SFW_EXPORT_API std::vector<Event*>* NativeInterface_getEvents(NativeInterface* pNativeInterface);

SFW_EXPORT_API bool NativeInterface_hasErrored(NativeInterface* pNativeInterface);

SFW_EXPORT_API bool NativeInterface_isWatching(NativeInterface* pNativeInterface);

SFW_EXPORT_API void NativeInterface_Delete(NativeInterface* pNativeInterface);

#endif
