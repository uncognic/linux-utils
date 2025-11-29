//
// Created by user on 11/25/2025.
//

#ifndef LINUX_UTILS_FILE_H
#define LINUX_UTILS_FILE_H
#include <stdio.h>

FILE* openFile(const char *fname, const char *mode);
int closeFile(FILE* file);
char* readLine(FILE* file, int line);
int writeFile(FILE* file, const char *buffer, size_t size);
int fileExists(const char *fname);

#endif //LINUX_UTILS_FILE_H