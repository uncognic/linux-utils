#ifndef FORMAT_H
#define FORMAT_H

#include <stddef.h>
#include <stdint.h>

char* humanReadable(uint64_t bytes);
char* convert(uint64_t bytes, char unit);
int indexLoc(char unit);
#endif