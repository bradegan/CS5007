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

void parse(char buf[], char* tokens[])
{
    if ((buf) != NULL){
        char* pch;
        
        char* token = strtok (buf," ,.-\t\n");
	printf ("token=%s\n",token);
	int i = 0;
	tokens[0] = token; 
	printf("token0=%s\n",tokens[0]);
        while (token != NULL)
        {
           // printf ("token=%s\n",token);
            token = strtok(NULL, " ,.-\t\n");
            printf ("token=%s\n",token);
	    i++;
            tokens[i]=token;	
	    printf("tokens at %d is %s\n",i, tokens[i]);
        }
        }
}

int main(int argc, char **argv){

	// Install our signal handler
	signal(SIGINT, sigint_handler);

	printf("You can only terminate by pressing Ctrl+C\n");

	while(1){
		printf("mini-shell>");
        char buf[BUFFER_SIZE];
	char* tokens[BUFFER_SIZE+10];
        fgets(buf, BUFFER_SIZE, stdin);
        printf("Buffer is: %s",buf);
	

        parse(buf, tokens);
	//	sleep(1);
	
	if (strcmp(tokens[0], "cd")==0 ){
	//	getcwd;
	printf("succes\n");
		
		if (chdir(tokens[1])== 0){
			printf("successfully changed directory\n");
	//	getcwd;
	}	
	
	}
//	return 0;

	}
	return 0;
}

// use chdir for
// check string compare against arguement and if so call the function
