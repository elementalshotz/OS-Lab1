#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#define THREADS 10

void *PrintHello(void *arg);
void *PrintMoon(void *arg);

int main(int ac, char **argv) {
//   pthread_t threadHello, threadMoon;
//   while (1) {
//     pthread_create(&threadHello, NULL, PrintHello, NULL);
//     usleep(1000);
//     pthread_create(&threadMoon, NULL, PrintMoon, NULL);
//     usleep(1000);
//   }
  pid_t child_pid;
  child_pid = fork();

  pthread_t thread_one, thread_two;
  void *res;

  if (child_pid == 0) {
    //printf("Child PID = %d, Parent PID = %d\n", getpid(), getppid());
    pthread_create(&thread_one, NULL, PrintHello, NULL);
    pthread_create(&thread_two, NULL, PrintMoon, NULL);
    pthread_join(thread_two, res);
    char *x = (char *)res;
    puts(x);
  }
}

// void *PrintHello(void *arg) {
//   for (int i = 0; i < THREADS; i++) {
//     puts("Hello world!");
//     usleep(200000);
//   }
//
//   pthread_exit(NULL);
// }
//
// void *PrintMoon(void *arg) {
//   for (int i = 0; i < THREADS; i++) {
//     puts("Hello moon");
//     usleep(200000);
//   }
//   pthread_exit(NULL);
// }

void *PrintHello(void *arg) {
  puts("Hello world!");
}

void *PrintMoon(void *arg) {
  puts("Hello moon");
  printf("Enter a message:");

  char myString[10];
  scanf("%s", myString);

  pthread_exit(myString);
}
