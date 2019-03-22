#include <stdio.h>
#include <unistd.h>
extern int count;
extern double time_ellapsed;

void msg(){
	printf("Hello!\n");
	sleep(1);
}

// Uses trace.c file to calculate time ellapsed.
// Count number of time a function is exectued using trace.c
int main(){

	

	int i;
	for(i= 0;i  < 10; ++i){
		msg();
	}
	printf("Count is... %d\n", count);
	printf("Time ellapsed %f\n", time_ellapsed);
	return 0;
}
