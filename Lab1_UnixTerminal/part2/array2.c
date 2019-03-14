// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.
#include <stdlib.h>

int main() {
    int* myArray = (int*)malloc(sizeof(int) * 400);
    myArray[0]=72;      
    myArray[10]=56;     
    myArray[11] = 842;  
    myArray[390] = 123; 
    myArray[399] = 111;
    free(myArray); 
    return 0;
}
