#include "types.h"
#include "stat.h"
#include "user.h"

void *stack[8];
void *retval[8];
int tid[8];

void *
thread(void *arg)
{
	thread_exit(0);
}

int
main(int argc, char **argv)
{
	int i;

	printf(1, "TEST2: ");

	for(i=0;i<8;i++)
		stack[i] = malloc(4096);

	for(i=0;i<7; i++) {
		tid[i] = thread_create(thread, 0, stack[i]);

		if(tid[i] == -1) {
			printf(1, "WRONG\n");
			exit();
		}
	}

	tid[7] = thread_create(thread, 0, stack[i]);
	if(tid[i] != -1) {
		printf(1, "WRONG\n");
		exit();
	}

	for(i=0;i<7;i++){
		if(thread_join(tid[i], &retval[i]) == -1) {
			printf(1, "WRONG\n");
			exit();
		}
	}

	//printf(1, "tid[7]: %d", tid[7]);
	if(thread_join(tid[7], &retval[7]) != -1){
		printf(1, "WRONG\n");
		exit();
	}

	for(i=0;i<7;i++)
		free(stack[i]);

	printf(1, "OK\n");

	exit();
}
