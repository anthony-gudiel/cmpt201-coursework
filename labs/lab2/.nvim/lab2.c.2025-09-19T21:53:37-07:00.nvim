#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  // All tokenizing code/getline() code reused from my last weeks lab
  char *buffer = NULL;
  size_t size = 0;

  int i = 0;
  // Infinitely repeat the process
  while (i < 1) {
    printf("Enter programs to run.\n");

    ssize_t num_characters = getline(&buffer, &size, stdin);

    if (num_characters == -1) {
      perror("getline");
      exit(EXIT_FAILURE);
    }
    // The newline character at the end of buffer causes an error with exec()
    // Therefore, we need to replace it
    if (num_characters > 0 && buffer[num_characters - 1] == '\n') {
      buffer[num_characters - 1] = '\0';
    }

    char *saveptr;
    char *ret = strtok_r(buffer, " ", &saveptr);
    char *args[10];
    args[0] = ret;
    // Always need to make sure our last argument is NULL
    args[1] = NULL;

    // pid will be 0 for child process, pid of child for parent process
    pid_t pid = fork();

    // If parent process, wait for child process to be done
    if (pid) {
      int wstatus = 0;
      if (waitpid(pid, &wstatus, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
      }
    } else {
      // If child process, execute the command given by the user
      if (execv(ret, args) == -1) {
        perror("execv");
        exit(EXIT_FAILURE);
      }
    }
  }
  free(buffer);
}
