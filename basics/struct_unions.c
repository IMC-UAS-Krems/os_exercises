#include <stdio.h>
#include "struct_unions.h"

int main() {
    point_t point;
    point.x = 1;
    point.y = 2;
    printf("Point = (%d, %d)\n", point.x, point.y);

    // this is a pointer to a struct
    point_t *pPoint = &point;
    pPoint->x = 2;
    pPoint->y = 4;
    printf("Point now is = (%d, %d)\n", point.x, point.y);

    coins_t change;
    for(int i = 0; i < sizeof(change) / sizeof(int); ++i)
    {
        scanf("%d", &(change.coins[i])); 
    }
    printf("There are %d quarters, %d dimes, %d nickels, and %d pennies\n",
        change.quarter, change.dime, change.nickel, change.penny);

}
