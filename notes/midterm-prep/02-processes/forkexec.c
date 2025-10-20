#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int pid = fork();
  if (pid) {
    int wstatus = 0;
    if (waitpid(pid, &wstatus, 0) == 0) {
      perror("waitpid() failed");
      exit(EXIT_FAILURE);
    }
  } else {
    char *args[] = {"/bin/ls", NULL};
    execv("/bin/ls", args);
  }
}
