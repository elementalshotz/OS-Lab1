#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#define NUM_THREADS 10

void *PrintHello(void* arg) {
  intptr_t id = (intptr_t)arg;
  printf("%s from thread %" PRIiPTR "\n", "Hello World", id);
  pthread_exit(NULL);
}

void *moon(void* arg) {
  pthread_t x;
  void *res;
  sleep(2);
  printf("%s\n", "Hello Moon!");
  pthread_create(&x, NULL, moon, NULL);
  pthread_exit(NULL);
}

int main(int ac, char * argv) {
  pthread_t thread;
  pthread_t threads[NUM_THREADS];
  void* ret;

  if (pthread_create(&thread, NULL, moon, NULL) != 0) {
    perror("pthread_create() error");
    exit(1);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    sleep(2);

    if (pthread_create(&threads[i], NULL, PrintHello, (void *)(i+1)) != 0) {
      perror("pthread_create() error");
      exit(1);
    }
  }

  pthread_exit(NULL);
}
