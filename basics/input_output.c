#include <stdio.h>

int main() {
    int number = 0;
    printf("Welcome to the test program\n");
    printf("Please enter a number: ");
    scanf("%d", &number);
    printf("The number squared is %d\n", number*number);

    return 0;
}