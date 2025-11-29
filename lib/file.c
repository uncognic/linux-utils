//
// Created by user on 11/25/2025.
//

#include <stdio.h>
#include <unistd.h>
#include "file.h"
#include <stdlib.h>
#include <string.h>

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

char* readLine(FILE* file, int line) {
    if (!file || line <= 0) return NULL;

    char buffer[256];
    int curLine = 1;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (curLine == line) {
            char* result = malloc(strlen(buffer) + 1);
            if (!result) return NULL;
            strcpy(result, buffer);
            return result;
        }
        curLine++;
    }

    return NULL;
}


// int writeFile(FILE* file, const char *buffer, size_t size) {}

int fileExists(const char *fname) {
    int e;
    if (access(fname, F_OK) == 0) {
        e = 10;
    } else {
        e = 0;
    }
    return e;
}
