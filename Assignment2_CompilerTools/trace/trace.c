#include <stdio.h>
#include<time.h>

int count = 0;
static clock_t start_time;
static clock_t stop_time;
double time_ellapsed = 0;


// Function that is executed before any function is exectured.
// Keeps track of count and time ellapsed by program.
__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){

	count ++;
	
	printf("Function entered\n");
	start_time = clock();
    


}
// Function that is executed every time after a method is executed.
// Calcs ellapsed time.
__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){
	printf("Function exited \n");
	stop_time = (double) clock();
	time_ellapsed += ((double) (stop_time - start_time) / CLOCKS_PER_SEC);

}





