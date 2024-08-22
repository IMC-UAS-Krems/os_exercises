#include <stdio.h>

int main() {
    int number = 0;
    printf("Welcome to the test program\n");
    printf("Please enter a number: ");
    scanf("%d", &number);
    printf("The number squared is %d\n", number*number);

    printf("The variable's address is %p\n", &number);

    int *pNumber = NULL;
    pNumber = &number;

    int number2 = 15;
    printf("pNumber now points to %d\n", *pNumber);

    pNumber = &number2;

    printf("pNumber now points to %d\n", *pNumber);

    return 0;
}