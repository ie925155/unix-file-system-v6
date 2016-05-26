#include <stdio.h>
#include <assert.h>

#include "file.h"
#include "inode.h"
#include "diskimg.h"

// remove the placeholder implementation and replace with your own
int file_getblock(struct unixfilesystem *fs, int inumber, int blockNum, void *buf) {
  //fprintf(stderr, "file_getblock(inumber = %d, blockNum = %d) unimplemented. returning -1\n", inumber, blockNum);
  struct inode in;
  int success = inode_iget(fs, inumber, &in);
  if(success == -1) return -1;

  int fd = fs->dfd;
  int index = inode_indexlookup(fs, &in, blockNum);
  int byte_read = diskimg_readsector(fd, index, buf);
  if(byte_read == -1) return -1;
  return byte_read;
}
