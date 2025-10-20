#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t forkpid = fork();
  if (forkpid == 0) {
    char *args[] = {"/bin/ls", "-a", "-l", "-h", NULL};
    execv("/bin/ls", args);
  } else {
    char *args[] = {"/bin/ls", "-a", NULL};
    execv("/bin/ls", args);
  }
}
