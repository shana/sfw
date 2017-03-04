#pragma once
enum EventType {
	CREATED = 0,
	DELETED = 1,
	MODIFIED = 2,
	RENAMED = 3
};

struct Event {
	EventType type;
	std::string directory, fileA, fileB;
};