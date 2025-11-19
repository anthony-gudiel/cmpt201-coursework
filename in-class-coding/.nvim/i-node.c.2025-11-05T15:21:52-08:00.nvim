#define _POSIX_C_SOURCE 200809L
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  struct stat sb;

  if (lstat(argv[1], &sb) == -1) {
    perror("lstat failed");
    exit(EXIT_FAILURE);
  }

  printf("File name: %s\n", argv[1]);
  printf("File Type:\n");

  if (S_ISREG(sb.st_mode)) {
    printf("Regular file\n");
  } else if (S_ISDIR(sb.st_mode)) {
    printf("Directory\n");
  } else {
    printf("Other\n");
  }
}
