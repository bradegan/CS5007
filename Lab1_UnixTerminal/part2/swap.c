// Write a C program that swaps two integers in function.

void swap_int(int* pa, int* pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main() {
    int a = 0;
    int b = 1;
    swap_int(&a, &b);
    return 0;
}
