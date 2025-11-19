#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int fd = open("tmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  const char *msg = "Hello World";

  write(fd, msg, strlen(msg));

  while (1) {
    sleep(30);
  }
}
