#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../lib/file.h"
#include "../lib/format.h"

int main(int argc, char *argv[]) {
    int flag = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            flag = 1;
        }
    }

    FILE *meminfo = openFile("/proc/meminfo", "r");
    if (!meminfo) return 1;

    for (int i = 1; i <= 3; i++) {
        char *buf = readLine(meminfo, 1);
        if (!buf) break;

        char *p = buf;
        while (*p && !isdigit(*p)) p++;

        if (*p) {
            uint64_t kb = strtoull(p, NULL, 10);
            uint64_t bytes = kb * 1024;

            if (flag) {
                char *hr = humanReadable(bytes);
                printf("%.*s %s\n", (int)(p - buf), buf, hr);
            } else {
                printf("%s", buf);
            }
        } else {
            printf("%s", buf);
        }

    }

    closeFile(meminfo);
    return 0;
}
