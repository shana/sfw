#ifndef FILEWATCHEROSX_H
#define FILEWATCHEROSX_H

#include "FileWatcherInterface.h"
#include <CoreServices/CoreServices.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <search.h>
#include <map>

namespace NSFW {

  struct FileDescriptor {
    dirent *entry;
    struct stat meta;
    std::string path;
  };

  struct Directory {
    dirent *entry;
    std::map<ino_t, FileDescriptor> fileMap;
    Directory *childDirectories;
    size_t numChildren;
    std::string path;
  };

  class FileWatcherOSX : public FileWatcherInterface {
  public:
    FileWatcherOSX(std::string path, std::queue<Event> &eventsQueue, bool &watchFiles);
    static void callback(
      ConstFSEventStreamRef streamRef,
      void *clientCallBackInfo,
      size_t numEvents,
      void *eventPaths,
      const FSEventStreamEventFlags eventFlags[],
      const FSEventStreamEventId eventIds[]
    );
    std::string getPath();
    static void *mainLoop(void *params);
    void processCallback();
    Directory *snapshotDir();
    bool start();
    Directory *mDirTree;

  private:
    std::queue<Event> &mEventsQueue;
    int mNumEvents;
    std::string mPath;
    pthread_t mThread;
    bool &mWatchFiles;
  };

}

#endif
