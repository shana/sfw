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

#endif
