#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child: Executing ls...\n");
        system("/bin/ls");
        printf("Child: Execution complete\n");
    }
    else {
        wait(NULL);
        printf("Parent: Child complete\n");
        printf("Value of PID of the child was %d\n", pid);
    }
}