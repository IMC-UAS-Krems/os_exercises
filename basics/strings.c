#include <stdio.h>
#include <string.h>

int main() {
    char *name = "John Doe";    // immutable string
    char name2[256] = "John Doe";   // mutable string

    printf("What is your forename? ");
    scanf("%s", name2);

    printf("Thank you, %s!\n", name2);
    if (strcmp(name2, "John") == 0) {
        printf("My name is John too!\n");
    }

    printf("Your name is %ld letters long\n", strlen(name2));

    char family_name[256];
    printf("What is your family name? ");
    scanf("%s", family_name);

    char full_name[256];
    strcat(name2, " ");
    strcat(name2, family_name);

    printf("So your full name is %s [Y/N]?\n", name2);
    char reply[256];
    scanf("%s", reply);
    if (strcmp(reply, "Y") == 0 || strcmp(reply, "y") == 0 || strcmp(reply, "Yes") == 0
        || strcmp(reply, "yes") == 0) {
            printf("Good, thank you! Bye!\n");
        }
    else {
        printf("Oh sorry, I got something wrong! Bye!\n");
    }
}
