#if WIN32
#include "stdafx.h"
#endif

#include "../includes/Lock.h"

Lock::Lock(pthread_mutex_t &mutex)
  : mMutex(mutex) {
  pthread_mutex_lock(&mMutex);
}

Lock::~Lock() {
  pthread_mutex_unlock(&mMutex);
}
