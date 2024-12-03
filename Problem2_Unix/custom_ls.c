#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;

    // Open directory (current directory by default if no argument given)
    if (argc < 2) {
        dir = opendir(".");
    } else {
        dir = opendir(argv[1]);
    }

    if (!dir) {
        perror("Unable to open directory");
        return 1;
    }

    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
