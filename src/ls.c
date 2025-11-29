#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int flag = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            flag = 1;
        }
    }

    struct dirent *dir;
    DIR *d = opendir(".");
    if (!d) {
        perror("opendir");
        return 1;
    }
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (flag == 1) {
                printf("%s\n", dir->d_name);
            } else {
                if (dir->d_name[0] != '.') {
                    printf("%s\n", dir->d_name);
                }
            }
        }


        closedir(d);
    }
    return(0);
}
