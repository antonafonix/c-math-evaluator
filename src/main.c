#include <stdio.h>

int get_priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main(void) {
    printf("Hello\n");
    return 0 ;
}
