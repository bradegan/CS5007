#include <stdio.h>
#include <string.h>

int main(int argsc, char** argv) {
    FILE *myFile;
    myFile = fopen(argv[1], "r");
    int max = 30;
    int mov =0;
    int num_instruction=0;
    int num_cycles=0;
    char* addset[] = {"add", "addq", "addb", "addl"};
    while (!(feof(myFile))) {
        char buffer[max];
        fgets(buffer, max, myFile);

        if (strstr(buffer, "mov")){
            mov++;
            num_instruction++;
            num_cycles += 1;
        }
        printf("MOV%d",mov);
        if (strstr(buffer, "add")){
            mov++;
            num_instruction++;
            num_cycles += 1;
        }
        
        //


        // line <- readline(t)
        // strtok read, lowercase,
        // parse_Line(line)
    }
}
