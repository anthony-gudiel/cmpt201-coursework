#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t forkpid = fork();

  if (forkpid) {
    int wstatus = 0;
    if (waitpid(forkpid, &wstatus, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
    if (WIFEXITED(wstatus)) {
      printf("Reason: %d\n", WEXITSTATUS(wstatus));
    } else {
      printf("Child did not exit normally\n");
    }

  } else {
    char *args[] = {"/bin/ls", "-a", "-l", "-h", NULL};
    if (execv("/bin/ls", args) == -1) {
      perror("execv");
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}
