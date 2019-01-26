#include "wrapper.h"

void *hello(void *message);

int main(int ac, char * argv)
{
	if (!threadCreate(hello, 10)) {
		perror("Can't create thread!");
		exit(1);
	}
}

void *hello(void *message) {
	int *x = (int *)message;
	printf("Hello %ls", x);
}
