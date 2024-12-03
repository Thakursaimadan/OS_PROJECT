#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file for writing; creates file if it does not exist
    FILE *file = fopen(argv[1], "w");
    if (!file) {
        perror("Unable to create file");
        return 1;
    }

    fclose(file);
    return 0;
}
