#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void check_file_type(const char *path) {
    struct stat statbuf;

    // Get the file status using stat
    if (stat(path, &statbuf) != 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Determine the file type
    if (S_ISREG(statbuf.st_mode)) {
        printf("%s is a regular file.\n", path);
    } else if (S_ISDIR(statbuf.st_mode)) {
        printf("%s is a directory.\n", path);
    } else if (S_ISCHR(statbuf.st_mode)) {
        printf("%s is a character device.\n", path);
    } else if (S_ISBLK(statbuf.st_mode)) {
        printf("%s is a block device.\n", path);
    } else if (S_ISFIFO(statbuf.st_mode)) {
        printf("%s is a FIFO (named pipe).\n", path);
    } else if (S_ISLNK(statbuf.st_mode)) {
        printf("%s is a symbolic link.\n", path);
    } else if (S_ISSOCK(statbuf.st_mode)) {
        printf("%s is a socket.\n", path);
    } else {
        printf("%s is an unknown file type.\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    check_file_type(argv[1]);

    return 0;
}

