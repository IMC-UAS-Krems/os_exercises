#include <stdio.h>

int main() {
    int numbers[5];
    numbers[0] = 10;
    numbers[1] = 11;
    numbers[2] = 12;
    numbers[3] = 14;
    numbers[4] = 15;
    
    printf("The array contents are: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    char vowels[1][5] = {
        {'a', 'e', 'i', 'o', 'u'}
    };

    char vowelsCaseSensitive[][5] = {
        {'a', 'e', 'i', 'o', 'u'},
        {'A', 'E', 'I', 'O', 'U'}
    };

    int i = 0;
    printf("Lower case: ");
    while(i < 5) {
        printf("%c ", vowelsCaseSensitive[0][i]);
        i++;
    }
    printf("\n");

    i = 0;
    printf("Upper case: ");
    while(i < 5) {
        printf("%c ", vowelsCaseSensitive[1][i]);
        i++;
    }
    printf("\n");
    return 0;
}
