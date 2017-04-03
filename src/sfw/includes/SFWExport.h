#ifndef SFW_EXPORT_H
#define SFW_EXPORT_H

//http://stackoverflow.com/questions/2164827/explicitly-exporting-shared-library-functions-in-linux#2164853

#ifdef SFW_IMPORTS

#if defined(_MSC_VER)
#define SFW_VISIBILITY __declspec(dllimport)
#define SFW_CALL __stdcall
#else
#define SFW_VISIBILITY
#define SFW_CALL
#endif

#else

//  Microsoft 
#if defined(_MSC_VER)
#define SFW_VISIBILITY __declspec(dllexport)
#define SFW_CALL __stdcall

//  GCC and friends
#elif defined(__GNUC__)
#define SFW_VISIBILITY __attribute__((visibility("default")))
#define SFW_CALL

#else
#define SFW_VISIBILITY
#define SFW_CALL
#endif

#endif

#define SFW_EXPORT_API(TYPE) SFW_VISIBILITY TYPE SFW_CALL
#define SFW_EXPORT_METHOD(TYPE) TYPE SFW_CALL

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
	SFW_EXPORT_API(NativeInterface*) NativeInterface_Create(const char* path);

	SFW_EXPORT_API(char*) NativeInterface_GetError(NativeInterface* instance);

	SFW_EXPORT_API(void) NativeInterface_GetEvents(NativeInterface* instance, SFW_Event** events, int* eventsCount);

	SFW_EXPORT_API(bool) NativeInterface_HasErrored(NativeInterface* instance);

	SFW_EXPORT_API(bool) NativeInterface_IsWatching(NativeInterface* instance);

	SFW_EXPORT_API(void) NativeInterface_Delete(NativeInterface* instance);
}

#endif
