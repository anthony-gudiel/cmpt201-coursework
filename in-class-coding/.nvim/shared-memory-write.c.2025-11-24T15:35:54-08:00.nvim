#define _POSIX_C_SOURCE 200809L
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *shmpath = argv[1];

  // Create shared memory object
  int shared_obj_fd = shm_open(shmpath, O_CREAT | O_EXCL | O_RDWR, 0600);
  if (shared_obj_fd == -1) {
    perror("shm_open() failed");
    exit(EXIT_FAILURE);
  }

  if (ftruncate(shared_obj_fd, sizeof(int)) == -1) {
    perror("ftruncate() failed");
    exit(EXIT_FAILURE);
  }

  int *addr = mmap(NULL, sizeof(*addr), PROT_READ | PROT_WRITE, MAP_SHARED,
                   shared_obj_fd, 0);
  *addr = 100;

  munmap(addr, sizeof(int));
  close(shared_obj_fd);
  shm_unlink(argv[1]);
  exit(EXIT_FAILURE);
}
