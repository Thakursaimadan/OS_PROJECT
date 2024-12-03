// custom_head.c
#include <stdio.h>

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
    char buffer[1024];
    for (int i = 0; i < lines && fgets(buffer, sizeof(buffer), file); i++) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
