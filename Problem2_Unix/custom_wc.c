#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Unable to open file");
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    int in_word = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if (isspace(ch)) in_word = 0;
        else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    fclose(file);
    printf("Lines: %d Words: %d Characters: %d\n", lines, words, chars);
    return 0;
}
