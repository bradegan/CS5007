// Modify this file for your assignment
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!


int BUFFER_SIZE = 80;


// Create a signal handler
void sigint_handler(int sig){
	// Ask yourself why 35?
	write(1,"mini-shell terminated\n",35); 
	exit(0);
}

int main(){

	// Install our signal handler
	signal(SIGINT, sigint_handler);

	printf("You can only terminate by pressing Ctrl+C\n");

	while(1){
		printf("mini-shell>");
		parse(argsc, **argv);
	//	sleep(1);
	}

	return 0;
}

int parse(int argsc, char **argv)
{   
   if ((argv[1]) != NULL){
    	char* pch;
    	char* str = argv[1];
    	pch = strtok (str," ,.-");
    	while (pch != NULL)
    	{
       	printf ("%s\n",pch);
        	pch = strtok(NULL, " ,.-");
    	}
        return 0;}
}
