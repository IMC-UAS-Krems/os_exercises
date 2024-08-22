#include <stdlib.h>
#include <stdio.h>
#include "dynamic_allocation.h"

#define MAX_PERSONS 10

int main() {
    person *pPerson = (person *) malloc(sizeof(person)); 
    pPerson->name = "John Doe";
    pPerson->age = 24;

    free(pPerson);

    person **pArrayPerson = (person **) malloc(MAX_PERSONS * sizeof(person *));
    for(int i = 0; i < MAX_PERSONS; i++) {
        pArrayPerson[i] = (person *) malloc(sizeof(person)); 
        pArrayPerson[i]->age = 30;
        pArrayPerson[i]->name = "John Smith";
    }

    for(int i = 0; i < MAX_PERSONS; i++) {
        free(pArrayPerson[i]);
    }
    free(pArrayPerson);

    return 0;
}
