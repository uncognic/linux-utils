//
// Created by user on 11/25/2025.
//

#include <stdio.h>
#include <unistd.h>
#include "file.h"

FILE* openFile(const char *fname, const char *mode) {
    FILE *file = fopen(fname, mode);
    if (!file) {
        perror("No such file");
        return nullptr;
    }
    return file;
}

int closeFile(FILE* file) {
    fclose(file);
    return 0;
}

// char* readLine(FILE* file, char *buffer, size_t size) {}

// int writeFile(FILE* file, const char *buffer, size_t size) {}

int fileExists(const char *fname) {
    int e;
    if (access(fname, F_OK) == 0) {
        e = 1;
    } else {
        e = 0;
    }
    return e;
}
