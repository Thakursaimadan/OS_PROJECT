#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Remove file
    if (unlink(argv[1]) != 0) {
        perror("Unable to remove file");
        return 1;
    }

    return 0;
}
