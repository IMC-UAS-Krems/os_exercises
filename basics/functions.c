#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Wrong number of parameters!\n");
        show_usage();
        return 0;
    }
    int number = atoi(argv[1]);
    int result = square(number);
    printf("Result = %d\n", result);

    square_by_reference(number, &result);
    printf("Result by reference = %d (%d)\n", result, number);

    printf("Bye!\n");
    return 0;
}

// Implementation of square
int square(int x) {
    return x*x;
}

void show_usage() {
    printf("Usage: functions <number>\n");
}

void square_by_reference(int x, int *result) {
    *result = x*x;
    x = 15;
}
