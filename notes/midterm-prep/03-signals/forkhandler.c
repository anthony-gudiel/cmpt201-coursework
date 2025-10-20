#define _POSIX_C_SOURCE
#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handler(int signum) {
  const char *msg = "Child finished\n";
  write(STDOUT_FILENO, msg, strlen(msg));
}

int main(void) {
  struct sigaction act = {0};
  act.sa_flags = 0;
  act.sa_handler = handler;
  sigemptyset(&act.sa_mask);

  if (sigaction(SIGUSR1, &act, NULL) == -1) {
    perror("sigaction() failed");
    exit(EXIT_FAILURE);
  }

  int pid = fork();
  if (pid) {
    while (1) {
      sleep(1);
    }
  } else {
    sleep(2);
    kill(getppid(), SIGUSR1);
  }
}
