#ifndef NSFW_NATIVE_INTERFACE_H
#define NSFW_NATIVE_INTERFACE_H

#include "Queue.h"
#include <vector>
#include "ExportHeader.h"

class NativeInterface {
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

SFW_EXPORT_API void* NativeInterface_Create(const char* path);

SFW_EXPORT_API std::string NativeInterface_getError(void* pNativeInterface);

SFW_EXPORT_API bool NativeInterface_hasErrored(void* pNativeInterface);

SFW_EXPORT_API bool NativeInterface_isWatching(void* pNativeInterface);

SFW_EXPORT_API void NativeInterface_Delete(void* pNativeInterface);

#endif
