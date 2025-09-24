#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// static makes it so that this variable cannot be seen outside of this file
static char *message = "CTRL-C Pressed.\n";
// We can't use printf, since it's not signal safe
// write() is signal safe
void handler(int signum) { write(STDOUT_FILENO, message, strlen(message)); }

int main() {
  struct sigaction act = {0};

  act.sa_flags = 0;
  act.sa_handler = &handler;
  sigemptyset(&act.sa_mask);

  pid_t pid = fork();

  if (pid) {
    if (sigaction(SIGINT, &act, NULL) == -1) {
      perror("sigaction");
      exit(EXIT_FAILURE);
    }
    while (1) {
      sleep(1);
    }

  } else {
    while (1) {
      sleep(3);
      printf("HEY Parent!\n");
      if (kill(getppid(), SIGINT) == -1) {
        perror("kill");
        exit(EXIT_FAILURE);
      }
    }
  }
}
