#ifndef LOCK_H
#define LOCK_H

#if WIN32
#include "win32/pthread.h"
#else
#include <pthread.h>
#endif

class Lock {
public:
  Lock(pthread_mutex_t &mutex);
  ~Lock();
private:
  pthread_mutex_t &mMutex;
};

#endif
