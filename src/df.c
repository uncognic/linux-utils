#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mntent.h>
#include <sys/statvfs.h>
#include <errno.h>
#include "../lib/format.h"

int main (int argc, char *argv[]) {
    int human = 0;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--human") == 0) {
            human = 1;
        }
        else if (strcmp(argv[i], "--help") == 0) {
            printf("Usage: df [-h]\n  -h, --human   print sizes in human readable format\n");
            return 0;
        }
    }
    FILE *mt = setmntent("/proc/mounts", "r");
    if (!mt) {
        mt = setmntent("/etc/mtab", "r");
    }
    if (!mt) {
        fprintf(stderr, "failed to open mounts: %s\n", strerror(errno));
        return 1;
    }
    struct mntent *ent;
    printf("%-20s %10s %10s %10s %6s  %s\n", "Filesystem", "Size", "Used", "Avail", "Use%", "Mounted on");
    while ((ent = getmntent(mt)) != NULL) {
        struct statvfs st;
        if (statvfs(ent->mnt_dir, &st) != 0) {
            continue;
        }
        uint64_t size = (uint64_t)st.f_blocks * st.f_frsize;
        uint64_t free = (uint64_t)st.f_bfree * st.f_frsize;
        uint64_t avail = (uint64_t)st.f_bavail * st.f_frsize;
        uint64_t used = size - free;
        int pct = (size == 0) ? 0 : (int)((used * 100ULL) / size);
        
        if (human) {
            char *size_h = humanReadable(size);
            char *used_h = humanReadable(used);
            char *avail_h = humanReadable(avail);
            printf("%-20s %10s %10s %10s %5d%%  %s\n", ent->mnt_fsname, size_h, used_h, avail_h, pct, ent->mnt_dir);
        } else {
            uint64_t size_k = size / 1024;
            uint64_t used_k = used / 1024;
            uint64_t avail_k = avail / 1024;
            printf("%-20s %10lu %10lu %10lu %5d%%  %s\n", ent->mnt_fsname, size_k, used_k, avail_k, pct, ent->mnt_dir);
        }
    }
    endmntent(mt);
    return 0;
}