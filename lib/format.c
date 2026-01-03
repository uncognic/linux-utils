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

int indexLoc(char unit) {
    const char *units[] = {"B", "K", "M", "G", "T", "P", "E", "Z"};
    int size = sizeof(units) / sizeof(units[0]);

    for (int i = 0; i < size; i++) {
        if (units[i][0] == unit) {
            return i;
        }
    }
    return -1;

}

char* convert(uint64_t bytes, char unit) {
    const char *units[] = {"B", "K", "M", "G", "T", "P", "E", "Z"};
    int i = 0;
    double eax = (double)bytes;
    int index = indexLoc(unit);
    if (index < 0) {
        return NULL;
    }


    while (eax >= 1024.0 && i < index) {
        eax /= 1024.0;
        i++;
    }
    static char hr[32];
    sprintf(hr, "%.2f %s", eax, units[index]);
    return hr;
}
