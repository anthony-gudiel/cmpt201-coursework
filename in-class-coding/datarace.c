#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 10000000
int cnt = 0;

void *thread_function(void *arg) {
  for (int i = 0; i < MAX; i++) {
    cnt += 1;
  }
  return NULL;
}

int main(void) {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread_function, NULL);

  pthread_t thread_id2;
  pthread_create(&thread_id2, NULL, thread_function, NULL);
  // Both threads are racing to be the first to change cnt
  // This will always give us an unpredictable cnt

  pthread_join(thread_id, NULL);
  pthread_join(thread_id2, NULL);
  printf("Done: answer is %d. \n", cnt);
}
