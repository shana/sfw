#ifndef NSFW_QUEUE_H
#define NSFW_QUEUE_H

#include <string>

extern "C" {
#include "../../openpa/src/opa_queue.h"
#include "../../openpa/src/primitives/opa_nt_intrinsics.h"
}

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

class EventQueue {
public:
  EventQueue();
  ~EventQueue();

  void clear();
  int count();
  Event *dequeue(); // Free this pointer when you are done with it
  void enqueue(
    EventType type,
    std::string directory,
    std::string fileA,
    std::string fileB = ""
  );

private:
  struct EventNode {
    OPA_Queue_element_hdr_t header;
    Event *event;
  };
  OPA_Queue_info_t mQueue;
  OPA_int_t mNumEvents;
};

#endif
