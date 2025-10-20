#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  char *args[] = {"/bin/notreal", "-a"};
  if (execv("/bin/notreal", args) == -1) {
    write(STDERR_FILENO, strerror(errno), strlen(strerror(errno)));
    // Or:
    perror("execv() failed");
    exit(EXIT_FAILURE);
  }
  return 0;
}
