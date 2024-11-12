#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void search(const char *dir_name, const char *file_name) {
    DIR *dir = opendir(dir_name);
    if (!dir) return;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, file_name) == 0) {
            printf("Found: %s/%s\n", dir_name, entry->d_name);
        }
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
            search(path, file_name);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <directory> <filename>\n", argv[0]);
        return 1;
    }
    search(argv[1], argv[2]);
    return 0;
}
