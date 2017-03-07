#ifndef NSFW_NATIVE_INTERFACE_EXPORT_H
#define NSFW_NATIVE_INTERFACE_EXPORT_H

#pragma once

#ifdef SFW_EXPORTS
#define SFW_EXPORT_API __declspec(dllexport)
#else
#define SFW_EXPORT_API __declspec(dllimport)
#endif

#include "Queue.h";
#include "NativeInterface.h";

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
