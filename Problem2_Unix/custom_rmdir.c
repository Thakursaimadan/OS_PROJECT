#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

void remove_directory(const char *dir_name) {
    DIR *dir = opendir(dir_name);
    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    struct dirent *entry;
    char path[1024];

    while ((entry = readdir(dir)) != NULL) {
        // Skip `.` and `..`
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full path
        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                // Recursively remove subdirectory
                remove_directory(path);
            } else {
                // Remove file
                if (unlink(path) != 0) {
                    perror("Unable to delete file");
                }
            }
        }
    }

    closedir(dir);

    // Remove the directory itself
    if (rmdir(dir_name) != 0) {
        perror("Unable to remove directory");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        return 1;
    }

    // Call recursive remove function
    remove_directory(argv[1]);

    return 0;
}
