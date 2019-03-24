// Modify this file for your assignment
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!
#include <string.h>


int BUFFER_SIZE = 80;


// Create a signal handler
void sigint_handler(int sig){
	// Ask yourself why 35?
	write(1,"mini-shell terminated\n",35);
	exit(0);
}

int parse(char* buf)
{
    if ((buf) != NULL){
        char* pch;
        char* str = buf;
        char* token = strtok (str," ,.-\t\n");
        while (token != NULL)
        {
            printf ("%s\n",token);
            token = strtok(NULL, " ,.-\t\n");
        }
        return token;}
}

int main(int argc, char **argv){

	// Install our signal handler
	signal(SIGINT, sigint_handler);

	printf("You can only terminate by pressing Ctrl+C\n");

	while(1){
		printf("mini-shell>");
        char buf[BUFFER_SIZE];

        fgets(buf, BUFFER_SIZE, stdin);
        printf("Buffer is: %s",buf);
	



        parse(buf);
	//	sleep(1);

	if (buf[0] == 'cd' ){
		getcwd;
		chdir(buf[1]);
		getcwd;
	}	
	}

	return 0;
}
// use chdir for
// check string compare against arguement and if so call the function
