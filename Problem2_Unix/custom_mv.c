#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // Rename or move file from source to destination
    if (rename(argv[1], argv[2]) != 0) {
        perror("Unable to move/rename file");
        return 1;
    }

    return 0;
}
