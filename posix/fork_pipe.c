#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    pid_t pid;

    int fd[2];

    if (pipe(fd) < 0) {
        fprintf(stderr, "Creaping pipe failed\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child: Executing ls...\n");
        system("/bin/ls > ls.txt");
        FILE *pFile = fopen("ls.txt", "r");
        if (pFile == NULL) {
            char *error_msg = "ERROR";
            write(fd[1], error_msg, strlen(error_msg));
        }
        char first_line[100];
        fscanf(pFile, "%s", first_line);
        write(fd[1], first_line, strlen(first_line));
        printf("Child: Execution complete\n");
    }
    else {
        wait(NULL);
        char response[256];
        read(fd[0], response, 256);
        printf("Parent: Child complete. Response was %s\n", response);
        printf("Value of PID of the child was %d\n", pid);
    }

    return 0;
}