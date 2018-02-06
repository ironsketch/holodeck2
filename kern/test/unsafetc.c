/*
 * Unsafe Thread Test
 */
#include <types.h>
#include <lib.h>
#include <thread.h>
#include <synch.h>
#include <test.h>

int THREADS = 10;
int GLOBALVAR = 0;
int TIMES = 100;
static struct semaphore *tsem = NULL;

static void init_sem(void){
	if(tsem == NULL){
		tsem = sem_create("tsem", 0);
		if(tsem == NULL){
			panic("threadtest: sem_create failed\n");
		}
	}
}

static void adding(void *junk, unsigned long num){
	(void)junk;
	(void)num;

	for(int i = 0; i < TIMES; i++){
		GLOBALVAR++;
	}
	V(tsem);
}

static void running(){
	char name[16];
	int i, resultEnd;

	for(i = 0; i < THREADS; i++){
		snprintf(name, sizeof(name), "threadtest%d", i);
		resultEnd = thread_fork(name, NULL, adding, NULL, i);
		if(resultEnd){
			panic("I'VE FAILED FOR THE LOVE OF SPAGHETTI MONSTER! thread_fork failed %s)\n",
					strerror(resultEnd));
		}
	}
	for(int i = 0; i < THREADS; i++){
		P(tsem);
	}
}

int unsafetc(int nargs, char **args){
	if(nargs > 1){
		int ch = atoi(args[1]);
		THREADS = ch;
	}
	if(nargs > 2){
		int ch2 = atoi(args[2]);
		TIMES = ch2;
	}
	init_sem();
	int shouldBe = THREADS * TIMES;
	kprintf("Starting thread test...\n");
	running();
	kprintf("Thread test done.\n");
	kprintf("And the result is: %d\n", GLOBALVAR);
	kprintf("But should be: %d\n", shouldBe);
	GLOBALVAR = 0;
	return 0;
}
