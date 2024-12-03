// shell.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char command[256];
    char *args[10];

    while (1) {
        printf("shell> ");
        fgets(command, sizeof(command), stdin);

        // Remove newline from fgets
        command[strcspn(command, "\n")] = 0;

        // Tokenize command
        int i = 0;
        args[i] = strtok(command, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        if (strcmp(args[0], "exit") == 0) break;

        pid_t pid = fork();
        if (pid == 0) {  // Child process
            // Add "./bin/" to execute custom utilities from bin directory
            char path[256] = "./bin/";
            strcat(path, args[0]);

            if (execv(path, args) == -1) {
                perror("Execution failed");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {  // Error forking
            perror("Fork failed");
        } else {  // Parent process
            wait(NULL);
        }
    }
    return 0;
}
