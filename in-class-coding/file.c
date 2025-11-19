#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int fd = open("tmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  const char *msg = "Hello World";
  char buf[sizeof(msg)];

  write(fd, msg, strlen(msg));
  lseek(fd, (-1 * sizeof(msg)) / 2, SEEK_CUR);
  read(fd, buf, 6);
  write(STDOUT_FILENO, buf, strlen(buf));
}
