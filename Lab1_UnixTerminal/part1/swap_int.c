#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}



void main(){

	x=5;
	y=10;

	swap_int(x, y);
	println(x);

}
