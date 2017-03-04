#pragma once
#include <vector>
#include <string>
#include "Queue.h"
#include "export_header.h"

SFW_EXPORT_API void* NativeInterface_Create(const char* path);

SFW_EXPORT_API std::string NativeInterface_getError(void* pNativeInterface);

SFW_EXPORT_API std::vector<Event*>* NativeInterface_getEvents(void* pNativeInterface);

SFW_EXPORT_API bool NativeInterface_hasErrored(void* pNativeInterface);

SFW_EXPORT_API bool NativeInterface_isWatching(void* pNativeInterface);

SFW_EXPORT_API void NativeInterface_Delete(void* pNativeInterface);
