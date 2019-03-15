#include <stdio.h>
#include <string.h>

// Cycle counts
// add subtract multiply divide move lea push pop ret
// .5  .5        2        6      .5   1  1    2    1

int main(int argsc, char **argv) {
    FILE *myFile;
    myFile = fopen(argv[1], "r");
    int max = 30;
    int mov = 0;
    int add = 0;
    int sub = 0;
    int mul = 0;
    int div = 0;
    int lea = 0;
    int push = 0;
    int pop = 0;
    int ret = 0;

    int num_instruction = 0;
    int num_cycles = 0;
    char *addset[] = {"add", "addq", "addb", "addl"};
    while (!(feof(myFile))) {
        char buffer[max];
        fgets(buffer, max, myFile);

        if ((strstr(buffer, "mov")) || (strstr(buffer, "MOV"))) {
            mov++;
            num_instruction++;
            num_cycles += 0.5;
        } else if ((strstr(buffer, "add")) || (strstr(buffer, "ADD"))) {
            add++;
            num_instruction++;
            num_cycles += 0.5;
        } else if ((strstr(buffer, "sub")) || (strstr(buffer, "SUB"))) {
            sub++;
            num_instruction++;
            num_cycles += 0.5;
        } else if ((strstr(buffer, "mul")) || (strstr(buffer, "MUL"))) {
            mul++;
            num_instruction++;
            num_cycles += 2;
        } else if ((strstr(buffer, "div")) || (strstr(buffer, "DIV"))) {
            div++;
            num_instruction++;
            num_cycles += 6;
        } else if ((strstr(buffer, "lea")) || (strstr(buffer, "LEA"))) {
            lea++;
            num_instruction++;
            num_cycles += 1;
        } else if ((strstr(buffer, "push")) || (strstr(buffer, "PUSH"))) {
            push++;
            num_instruction++;
            num_cycles += 1;
        } else if ((strstr(buffer, "pop")) || (strstr(buffer, "POP"))) {
            pop++;
            num_instruction++;
            num_cycles += 2;
        } else if ((strstr(buffer, "ret")) || (strstr(buffer, "RET"))) {
            ret++;
            num_instruction++;
            num_cycles += 1;
        }
    }
    printf("MUL%d", mul);
    printf("MOV%d", mov);
    printf("SUB%d", sub);
    printf("ADD%d", add);
    printf("DIV%d", div);
    printf("LEA%d", lea);
    printf("PUSH%d", push);
    printf("POP%d", pop);
    printf("RET%d", ret);




}
