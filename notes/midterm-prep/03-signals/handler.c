#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handler(int signum) {
  char *msg = "Signal received";
  write(STDOUT_FILENO, msg, strlen(msg));
}

int main(void) {
  struct sigaction act = {0};
  act.sa_handler = handler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  if (sigaction(SIGINT, &act, NULL) == -1) {
    perror("sigaction() failed");
    exit(EXIT_FAILURE);
  }

  while (1) {
    sleep(1);
    raise(SIGINT);
  }
}
