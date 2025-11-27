//
// Created by user on 11/25/2025.
//

#include <stdio.h>
#include <string.h>
#include "../lib/file.h"
#include "../lib/format.h"

int main(int argc, char *argv[]) {
    int flag;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            flag = 1;
        }
    }
    const char *fields[] = {"MemTotal", "MemFree", "MemAvailable", "Cached", "SwapTotal", "SwapFree"};
    size_t n_fields = sizeof(fields) / sizeof(fields[0]);
    FILE *meminfo = openFile("/proc/meminfo", "r");
    if (meminfo == NULL) {
        return 1;
    }
    char line[256];
    printf("Mem:\n");
    while (fgets(line, sizeof(line), meminfo)) {
        printf("%s", line);
    }
    closeFile(meminfo);
}