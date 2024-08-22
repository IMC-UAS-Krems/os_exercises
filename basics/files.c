#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *pFile = NULL;

    if (argc != 3) {
        printf("Usage: ./files <file_name> <line>\n");
        return 0;
    }

    printf("Opening file for appending line...\n");
    pFile = fopen(argv[1], "a"); // Opening the file in append mode
                                 // Other modifiers are "r" - read mode, "w" - write mode
    if (pFile == NULL) {
        printf("Failed to open file %s\n", argv[1]);
        return -1;
    }
    fprintf(pFile, "%s\n", argv[2]);
    printf("Write completed successfully\n");

    fclose(pFile);

    // Alternatively, use the system calls open/write/close
    int fd = open(argv[1], O_WRONLY | O_APPEND);
    write(fd, argv[2], strlen(argv[2]));
    close(fd);

    return 0;
}
