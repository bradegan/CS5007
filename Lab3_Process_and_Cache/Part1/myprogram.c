#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Program that runs 3 unique commands/programs using the process API. 
// ps command is used more than once to illustrate changes in process status.
int main(){
	printf("Running multiple processes. Parent's PID is %d.\n\n", getpid());
		
	char* myargv[16];	

	if(fork()==0){
		myargv[0]="/bin/cat";	
		myargv[1]="example1.c";
		myargv[2]=NULL;
		printf("Using cat to read example1.c. PID is %d.\n", getpid());
		execve(myargv[0], myargv, NULL);
		fprintf(stderr, "Issue with execve command. Child did not exit.\n");
		exit(1);
	}
		
	wait(NULL);
	if(fork()==0){
		myargv[0]="./example1";	
		myargv[1]=NULL;
		printf("\nRunning example1. PID is %d.\n", getpid());
		execve(myargv[0],myargv,NULL);
		fprintf(stderr, "Issue with execve command. Child did not exit.\n");
		exit(1);
	}
	wait(NULL);
	if(fork()==0){
		myargv[0]="/bin/ps";	
		myargv[1]=NULL;
		printf("\nCalling ps to check processes. PID is %d.\n", getpid());
		execve(myargv[0],myargv, NULL);
		fprintf(stderr, "Issue with execve command. Child did not exit.\n");
		exit(1);
	}

	wait(NULL);
	printf("\nAll processes besides main should be finished. Calling ps to confirm.\n");
	myargv[0]="/bin/ps";	
	myargv[1]=NULL;
	execve(myargv[0],myargv, NULL);
	
	return 0;
}

