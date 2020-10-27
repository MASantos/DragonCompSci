#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifdef FIBO
#include "fibo.h"
#ifndef FIBON 
#define FIBON (fibo_t) 5*1000*1000*1000
#endif
#define childwork() printf("fib(%llu)=%llu\n",FIBON,fib(FIBON));
#define BUSY "computation lasted"
#else
#define childwork()  nanosleep(&timeout,NULL);
#define BUSY "slept for"
#endif

#define NUMBER_CORES 8
#define CHILD_SLEEP 10*NUMBER_CORES
#define MAXCHILDREN 100

int main(int argc, const char** argv){
	time_t begin = time(NULL);
	int nch = MAXCHILDREN/25;
		
	if( argc > 1 && strncmp(argv[1],"-",1)==0 ){
		printf("Usage: %s [number_of_children (%d)]\n\n"\
			"Spawns number_of_children and waits for them to finish before wrapping up.\n"\
			"Max number allowed is %d. If number_of_children is larger it automatically reset to that max value.\n",\
			argv[0], nch,MAXCHILDREN\
		);
		exit(0);
	}
	if (argc > 1){ 
		nch = atoi(argv[1]);
		nch = (nch<0||nch>MAXCHILDREN)? MAXCHILDREN*(nch>0?10:1)/10 : nch ;
	}
	
	pid_t* pids = (pid_t*) calloc(nch,sizeof(pid_t));

	struct timespec timeout;
	timeout.tv_sec = CHILD_SLEEP/nch;
	timeout.tv_nsec = (CHILD_SLEEP%nch)*100*1000*1000;
	printf("Will try spawning %d children each living for %4.f sec\n",nch,timeout.tv_sec+1e-9*timeout.tv_nsec);

	pid_t pid , sumOfpids = 0;	
	int i , n=0, status;
	for( i= 0 ; i < nch ; i++){
		pid = fork();
		n++;
		switch(pid){
			case -1:
				printf("WARNING: Error while forking a child. Will try to continue with remaining %d children.\n",nch-n);
				n--;
				continue;
				break;
			case 0:
				begin = time(NULL);
				printf("Hi, I'm child %d. Going to sleep now\n",n);
				//printf("fib(%llu)=%llu\n",FIBON,fib(FIBON));
				//nanosleep(&timeout,NULL);
				childwork();
				printf("Child %d %s %tu sec. Bye\n",n,BUSY,time(NULL)-begin);
				exit(0);
				break;
			default:
				sumOfpids += pid;
				printf("Parent: saw child %d (%d) parting\n",n,pid);
				break; 
		}

	}

	printf("All children submitted. Waiting for their termination...\n");

	/*
	//all theese are equivalent ways for waiting FOR ALL children -caveat: if a child stops (but not terminating) waitn returns a >0 value too!
	//while( waitpid(0,&status,0)>0 );
	//while( wait4(-1,&status,0,0)>0 );
	//while( wait3(&status,0,0)>0 );
	//while( wait(&status)>0 );
	
	while( sumOfpids > 0 ){
		pid = wait(&status);
		if( pid == -1 ){ 
			printf("Error in child or while waiting for one\n");
			exit(1);
		}
		sumOfpids -= pid ;
		printf("Child %d finished\n",pid); 
	}
	*/
	//wait and check exit status
	int options = WUNTRACED;
	while( (pid=wait3(&status,options,0))>0){
		int wexstat;
		if ( WIFEXITED(status) ){
			wexstat=WEXITSTATUS(status);
			printf("Child %d terminated with an exit call %d\n",pid,wexstat);
		}
		if ( WIFSIGNALED(status)) {
			wexstat=WTERMSIG(status);
			printf("Child %d terminated with a term signal  %d\n",pid,wexstat);
			if( WCOREDUMP(status) ) printf("Coredump was created\n");
		}
		if ( WIFSTOPPED(status)) {
			wexstat=WSTOPSIG(status);
			printf("Child %d stopped with signal %d\n",pid,wexstat);
		}
	}
	printf("All %d children finished.Elapsed time aprox. %tu sec.\n",n,time(NULL)-begin);
	
	return 0;
}


