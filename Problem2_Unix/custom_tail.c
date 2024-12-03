// custom_tail.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <num_lines>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Unable to open file");
        return 1;
    }

    int lines = atoi(argv[2]);
    char **buffer = malloc(lines * sizeof(char *));
    for (int i = 0; i < lines; i++) buffer[i] = malloc(1024);

    int count = 0;
    while (fgets(buffer[count % lines], 1024, file)) {
        count++;
    }

    int start = count > lines ? count - lines : 0;
    for (int i = start; i < count; i++) {
        printf("%s", buffer[i % lines]);
    }

    fclose(file);
    for (int i = 0; i < lines; i++) free(buffer[i]);
    free(buffer);
    return 0;
}
