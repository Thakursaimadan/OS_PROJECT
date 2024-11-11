#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        return 1;
    }

    // Create directory with default permissions
    if (mkdir(argv[1], 0755) != 0) {
        perror("Unable to create directory");
        return 1;
    }

    return 0;
}
