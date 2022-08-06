#ifndef FILE_H
#define FILE_H

#include "pparser.h"

typedef unsigned int FILE_SEEK_MODE;

enum {
  FILE_SET,
  FILE_CUR,
  FILE_END
};

typedef unsigned int FILE_MODE;
enum {
  FILE_MODE_READ,
  FILE_MODE_WRITE,
  FILE_MODE_APPEND,
  FILE_MODE_INVALID
};

struct disk;
typedef void* (*FS_OPEN_FUNCTION) (struct disk* disk, struct path_part* path, FILE_MODE mode);
typedef int (*FS_RESOLVE_FUNCTION) (struct disk* disk);

struct filesystem {
  // Filesystem should return 0 from resolve if the provided disk is using it's filesystem
  FS_RESOLVE_FUNCTION resolve;
  FS_OPEN_FUNCTION open;

  char name[20];
};

struct file_descriptor {
  // The descriptor index
  int index;
  struct filesystem* filesystem;
  
  // Private data for internal file descriptor
  void* private;

  // The disk that the file desscriptor should be used on
  struct disk* disk;
};

void fs_init();
int fs_open(const char* filename, const char* mode_str);
void fs_insert_filesystem(struct filesystem* filesystem);
struct filesystem* fs_resolve(struct disk* disk);

#endif