// To be compiled with: gcc -lpthread threads.c -o threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NTHREADS 64

// This global array is our 'canvas' we are painting on.
// It is 64 rows by 64 columns (each pixel stores 3 color components, R,G,B)
int colors[64][64*3];
// Initialize a global variable to store the current color (TA at office hours says this is ok).
int color = 0;
// Initialize a mutex. The canvas is a global variable, so when each thread works upon the canvas, it must lock and then
// unlock it to avoid overwriting another thread's work.
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Paint function is called from each child. The mutex lock/unlock occurs inside the function. 
void *paint(void* arg){
    pthread_mutex_lock(&mutex1);
    printf("Artist %d is painting\n", color);
    int i = 0;
    for(i =0; i < 64*3; i++){
        colors[color][i] = color;
    }
    color++;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main(int argc, char** argv){
    // Establish array of pthread_t objects.
    pthread_t tids[NTHREADS];
    int i = 0;
    for(i = 0; i < NTHREADS; i++) {
        // Call the paint function for each thread.
        pthread_create(&tids[i], NULL, paint, NULL);
    }
    // Call pthread_join to rejoin the threads.
    for(i = 0; i < NTHREADS; i++){
        pthread_join(tids[i], NULL);
    }
    printf("Masterpiece(threads.ppm) is being assembled\n");

    // Assemble the threads.ppm file.
    FILE *fp;
    fp = fopen("threads.ppm","w+");
    fputs("P3\n",fp);
    fputs("64 64\n",fp);
    fputs("255\n",fp);
    int j = 0;
    for(i =0; i < 64;i++){
    for(j =0; j < 64*3; j++){
    fprintf(fp,"%d",colors[i][j]);
    fputs(" ",fp);
    }
    fputs("\n", fp);
    }
    fclose(fp);
    return 0;
}

