#include <stdio.h>		//printf
#include <unistd.h>		//fork
#include <stdlib.h>		//exit

#define NUMBER_CHILDREN 8

int main(){
	pid_t pid;
	for ( int i= 0 ; i < NUMBER_CHILDREN ; i++){
		pid = fork();
		
		switch( pid ) {
			case -1:
				printf("ERROR: spawning of child process failed\n");
				return 1;
				break;
			case 0:
				printf("Hello World! I'm the child number %d. Bye!\n",i+1);
				exit(0);
				break;
			default:
				printf("Hi, I'm the parent of the process with pid=%d\n",pid);
				break;
		}
	}
	printf("I'm the parent waiting for all my %d offsprings to come back and report\n",NUMBER_CHILDREN);
	int status;
	while( (pid=wait(&status)) > 0) {
		printf("My child with pid=%d is back!\n",pid);
	}
	printf("All children returned\n");
	return 0;
}
