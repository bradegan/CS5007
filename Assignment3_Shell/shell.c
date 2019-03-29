// Modify this file for your assignment

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h> // This is new!
#include <string.h>


int BUFFER_SIZE = 80;


// Create a signal handler
void sigint_handler(int sig){
	// Ask yourself why 35?
	write(1,"mini-shell terminated\n",35);
	exit(0);
}

// "aa bb cc"
// {_ _ _ _ _}
// {"aa", _ _ ... }
// {"aa", "bb", "cc", NULL, ...}
void parse(char buf[], char* tokens[])
{
	if ((buf) != NULL){
		char* token = strtok (buf," \t\n");
		printf ("token=%s\n",token);
		int i = 0;
		tokens[0] = token; 
		// printf("token0=%s\n",tokens[0]);
		while (token != NULL)
		{
			// printf ("token=%s\n",token);
			token = strtok(NULL, " \t\n");
			printf ("token=%s\n",token);
			i++;
			tokens[i]=token;	
			// printf("tokens at %d is %s\n",i, tokens[i]);
		}
	}
}


void parsePipe(char buf[], char* tokens[])
{
	if ((buf) != NULL){
		char* token = strtok (buf,"|");
		printf ("token=%s\n",token);
		int i = 0;
		tokens[0] = token; 
		// printf("token0=%s\n",tokens[0]);
		while (token != NULL)
		{
			// printf ("token=%s\n",token);
			token = strtok(NULL, "|");
			printf ("token=%s\n",token);
			i++;
			tokens[i]=token;	
			// printf("tokens at %d is %s\n",i, tokens[i]);
		}
	}
}




int runGame(){
    srand(time(0));
    int numbers_guessed[5];

    for (int i=0;i<1;i++){

    int x = (rand()%10)+1;
    int guess;
    int times_guessed;


    while(guess != x){
    printf("Please enter your guess: \n");
    scanf("%d", &guess);
    if (guess > x){printf("Please guess lower \n");
    times_guessed +=1;}
    else if (guess < x){printf("Please guess higher \n");
    times_guessed +=1;
    }
    }
    {printf("Correct guess! \n");}
    numbers_guessed[i]= times_guessed;
   }
}




int main(int argc, char **argv){

	// Install our signal handler
	signal(SIGINT, sigint_handler);

	printf("You can only terminate by pressing Ctrl+C\n");
	char buf[BUFFER_SIZE];
	char* tokens[BUFFER_SIZE];
	int p[2];

	while(1){
		printf("mini-shell>");
		fgets(buf, BUFFER_SIZE, stdin);
		// printf("Buffer is: %s",buf);
		parse(buf, tokens);
		//	sleep(1);

		if (strcmp(tokens[0], "cd")==0 ){
			printf("%s\n", tokens[1]);
			if (chdir(tokens[1])== 0){
				printf("successfully changed directory\n");
				//	getcwd;
			}	

		}
		else if (strcmp(tokens[0], "exit")==0 ){
			exit(1);
		}

		else if (strcmp(tokens[0], "help")==0 ){
			printf("Built in cmds:\n cd - change directory \n game - guessing game \n help - help file ");
			}
		
		else if (strcmp(tokens[0], "game")==0){
		        runGame();	
			exit(1);	
			}
		else if (strstr(buf, "|") == 0) { 
			pipe(p);
			
			if (fork() == 0) {
                                execvp(tokens[0], tokens);
                                fprintf(stderr, "Command not recognized\n");
                        }
	
		        if(fork() == 0) { 
                                execvp(tokens2[0], tokens2);
                                fprintf(stderr, "Command not recognized\n");
				exit(1);
			}
		}
		else {
			if (fork() == 0) {
				execvp(tokens[0], tokens);
				fprintf(stderr, "Command not recognized\n");
				exit(1);
			}	
			wait(NULL);
			
	
/*
			pipe(token)
				read(token[0],( ,sizeof()));
			dup2(token[1],STDOUT_fileno);

			exceup < 0 if fork <=0)
				pid_t pid = fork();
			if (pid==0 = if (fork() ==0)
					else{

					(| if (fork)
					 dups2(P[1],STDOUT_FILENO);
					 close *2
					 (| else{
					  close(P[1]
						  read()
						  process output
						  wait(NULL);
						  execVP/builtin
						  else {wait	}
						  //	return 0;

						  }
						  return 0;
						  }

						  // use chdir for
						  //
						  */
						  // check string compare against arguement and if so call the function
		}
	}
	return 0;
}
