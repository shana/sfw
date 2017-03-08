#ifndef SFW_EXPORT_H
#define SFW_EXPORT_H

//http://stackoverflow.com/questions/2164827/explicitly-exporting-shared-library-functions-in-linux#2164853

#if defined(_MSC_VER)
//  Microsoft 
#ifdef SFW_EXPORTS
#define SFW_EXPORT_API __declspec(dllexport)
#else
#define SFW_EXPORT_API __declspec(dllimport)
#endif
#elif defined(__GNUC__)
//  GCC
#ifdef SFW_EXPORTS
#define SFW_EXPORT_API __attribute__((visibility("default")))
#else
#define SFW_EXPORT_API
#endif
#else
//  do nothing and hope for the best?
#define SFW_EXPORT_API
#pragma warning Unknown dynamic link import/export semantics.
#endif

#include "Queue.h"
#include "NativeInterface.h"

struct SFW_Event {
	EventType type;
	char* directory;
	char* fileA;
	char* fileB;
};

extern "C"
{
	SFW_EXPORT_API NativeInterface* NativeInterface_Create(const char* path);

	SFW_EXPORT_API std::string NativeInterface_getError(NativeInterface* instance);

	SFW_EXPORT_API void __stdcall NativeInterface_getEvents(NativeInterface* instance, SFW_Event** events, int* eventsCount);

	SFW_EXPORT_API bool NativeInterface_hasErrored(NativeInterface* instance);

	SFW_EXPORT_API bool NativeInterface_isWatching(NativeInterface* instance);

	SFW_EXPORT_API void NativeInterface_Delete(NativeInterface* instance);
}

#endif
