#pragma once
#include "export_header.h"

enum EventType {
	CREATED = 0,
	DELETED = 1,
	MODIFIED = 2,
	RENAMED = 3
};

SFW_EXPORT_API struct Event {
	EventType type;
	std::string directory, fileA, fileB;
};