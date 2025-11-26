//
// Created by user on 11/25/2025.
//

#include "format.h"
#include <stdint.h>
#include <stdio.h>

char* humanReadable(uint64_t bytes) {
    const char *unit[] = {"B", "K", "M", "G", "T", "P", "E", "Z"};
    int size = sizeof(unit) / sizeof(unit[0]);
    int i = 0;
    double eax = (double)bytes;

    while (eax >= 1024.0 && i < size - 1) {
        eax /= 1024.0;
        i++;
    }

    static char hr[32];
    sprintf(hr, "%.2f %s", eax, unit[i]);
    return hr;
}
