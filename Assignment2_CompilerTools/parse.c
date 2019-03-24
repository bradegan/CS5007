// Implement a working parser in this file that splits text into individual tokens.

#include <stdio.h>
#include <string.h>

int main (int argsc, char **argv)
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
