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
	void* mNativeInterface;
};

struct EventSimple {
	EventType type;
	char* directory;
	char* fileA;
	char* fileB;
};

struct TestStruct
{
	int value;
	char* name;
	char* name2;
	char* name3;
};

extern "C"
{
	SFW_EXPORT_API void* NativeInterface_Create(const char* path);

	SFW_EXPORT_API std::string NativeInterface_getError(void* pNativeInterface);

	SFW_EXPORT_API void __stdcall NativeInterface_getEvents(void* pNativeInterface, EventSimple** events, int* eventsCount);

	SFW_EXPORT_API bool NativeInterface_hasErrored(void* pNativeInterface);

	SFW_EXPORT_API bool NativeInterface_isWatching(void* pNativeInterface);

	SFW_EXPORT_API void NativeInterface_Delete(void* pNativeInterface);

	SFW_EXPORT_API void TestStructMethod(TestStruct** items, int* itemsCount);
}

#endif
