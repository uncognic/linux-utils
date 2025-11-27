//
// Created by user on 11/25/2025.
//
#ifndef LINUX_UTILS_FORMAT_H
#define LINUX_UTILS_FORMAT_H

#include <stddef.h>
#include <stdint.h>

char* humanReadable(uint64_t bytes);
char* convert(uint64_t, char unit);
int indexLoc(char unit);
#endif //LINUX_UTILS_FORMAT_H