// Compile with: gcc fileread.c -o fileread
// Run with: ./fileread

// Fill in the code!

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* f;

    f = fopen("./data.txt", "r");

    if (f == NULL) {
        printf("fopen failed");
        exit(1);
    }

    char buffer[255];

    while (fscanf(f, "%s", buffer) != EOF) {
        printf("Red Sox wins are: %s\n",buffer);
    }

    fclose(f);

    return 0;
}
