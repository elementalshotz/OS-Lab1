#include "wrapper.h"
#include <semaphore.h>

void *hello(void *message);
void *moon(void *arg);

sem_t semaphore;

int main(int ac, char * argv)
{
	sem_init(&semaphore, 0, 1);
	
	if (!threadCreate(hello, 10)) {
		perror("Can't create thread!");
		exit(1);
	}

	if (!threadCreate(moon, 10)) {
		perror("Can't create thread!");
		exit(1);
	}

	sem_destroy(&semaphore);
}

void *hello(void *message) {
	while (1) {
		while (sem_wait(&semaphore) != 0) {}

		for (int i = 0; i < 10; i++) {
			puts("Hello World!");
			sleep(1);
		}

		sem_post(&semaphore);
		usleep(200000);
	}
}

void *moon(void *arg) {
	while (1) {
		while (sem_wait(&semaphore) != 0) {}

		for (int i = 0; i < 10; i++) {
			puts("Hello moon");
			usleep(200000);
		}

		sem_post(&semaphore);
		usleep(200000);
	}
}
