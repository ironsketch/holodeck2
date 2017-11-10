/*
 * Thread test code.
 */
#include <types.h>
#include <lib.h>
#include <thread.h>
#include <synch.h>
#include <test.h>

int NTHREADS = 10;

static struct semaphore *tsem = NULL;

static
void
init_sem(void)
{
	if (tsem==NULL) {
		tsem = sem_create("tsem", 0);
		if (tsem == NULL) {
			panic("threadtest: sem_create failed\n");
		}
	}
}

static
void
quietthread(void *junk, unsigned long num)
{
	(void)junk;
	int ch = '0' + num;
	putch(ch);	

	V(tsem);
}

static
void
runthreads()
{
	char name[16];
	int i, result;

	for (i=0; i<NTHREADS; i++) {
		snprintf(name, sizeof(name), "threadtest%d", i);
		result = thread_fork(name, NULL, quietthread, NULL, i);
		if (result) {
			panic("threadtest: thread_fork failed %s)\n", 
			      strerror(result));
		}
	}

	for (i=0; i<NTHREADS; i++) {
		P(tsem);
	}
}


int
threadfun(int nargs, char **args)
{
//	if(nargs > 1){
//		NTHREADS = (int)args[1];
//	}
	int ch = atoi(args[1]);
	kprintf("Amount of arguments passed: %d\n", nargs);
	kprintf("Number passed: %d\n", ch);
	if(nargs > 1){
		NTHREADS = ch;
	}
	init_sem();
	kprintf("Starting thread test...\n");
	runthreads();
	kprintf("\nThread test done.\n");

	return 0;
}
