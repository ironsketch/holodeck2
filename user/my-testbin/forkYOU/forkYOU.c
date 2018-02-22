#include <unistd.h>
#include <stdio.h>

int main(){
	int pid = 1;
	int x = 0;
	int butt = fork();
	int butt2 = waitpid(pid, &x, 0);
	int butt3 = getpid();
	printf("Fork Call: %d\n", butt);
	printf("Waitpid Call: %d\n", butt2);
	printf("Getpid Call: %d\n", butt3);
	return 0;
}
