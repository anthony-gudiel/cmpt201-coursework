#define POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // Buffer stores the address of the buffer containing the text
  // getline() allocates memory for buffer, so we must free() before the end of
  // the program or on failure
  char *buffer = NULL;

  // We set size to 0, allowing getline() to allocate an appropriate buffer size
  // for us, instead of setting it ourselves
  size_t size = 0;
  printf("Please enter some text: ");
  ssize_t number_of_characters = getline(&buffer, &size, stdin);

  // If something goes wrong with getline(), display error and perform cleanup
  if (number_of_characters == -1) {
    perror("getline failed");
    exit(EXIT_FAILURE);
  }

  // saveptr will save our progress while tokenizing (store the rest of the
  // sentence after the delimiter is encountered)
  char *saveptr;
  // ret will contain the value of the word(s) encountered before the delimiter
  // was hit
  char *ret = strtok_r(buffer, " ", &saveptr);
  printf("Tokens: \n");
  printf("%s\n", ret);

  // Now we just need to continue this process, stopping when ret2 is null, as
  // that means we have encountered the last delimiter within the sentence
  char *ret2 = "";
  while (ret2 != NULL) {
    // The subsequent function calls to strtok_r() are different than the first
    // call This time we pass in NULL, as we want to parse the same string that
    // we already passed in (buffer)
    ret2 = strtok_r(NULL, " ", &saveptr);
    if (ret2 != NULL) {
      printf("%s\n", ret2);
    }
  }

  free(buffer);
}
