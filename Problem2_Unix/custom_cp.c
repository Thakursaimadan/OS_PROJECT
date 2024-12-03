// custom_cp.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (!src) {
        perror("Unable to open source file");
        return 1;
    }

    FILE *dest = fopen(argv[2], "wb");
    if (!dest) {
        perror("Unable to open destination file");
        fclose(src);
        return 1;
    }

    char buffer[1024];
    size_t bytes;
    // Copy contents of source to destination
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}
