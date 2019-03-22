#include <stdio.h>



void msg(){
	printf("Hello!\n");
	
}

// Uses trace.c file to calculate time ellapsed.
// Count number of time a function is exectued using trace.c
int main(){

	extern int count;
	extern double time_ellapsed;
	

	int i;
	for(i= 0;i  < 100; ++i){
		msg();
	}
	printf("Count is... %d\n", count);
	printf("Time ellapsed %f\n", time_ellapsed);
	return 0;
}
