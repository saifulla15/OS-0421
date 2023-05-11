#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct dirent *dp;
    DIR *dir;
    struct stat filestat;

    /* If no directory is specified, use the current directory */
    char *dirname = ".";
    if (argc > 1) {
        dirname = argv[1];
    }

    /* Open the directory */
    if ((dir = opendir(dirname)) == NULL) {
        perror("opendir");
        exit(1);
    }

    /* Read the directory and print file names and details */
    while ((dp = readdir(dir)) != NULL) {
        /* Get file status */
        char filename[256];
        snprintf(filename, sizeof(filename), "%s/%s", dirname, dp->d_name);
        if (stat(filename, &filestat) == -1) {
            perror("stat");
            continue;
        }

        /* Print file details */
        printf("%s ", dp->d_name);
        printf("%ld ", filestat.st_size);
        printf("%lo ", (unsigned long) filestat.st_mode);
        printf("%s", ctime(&filestat.st_mtime));
    }

    /* Close the directory */
    closedir(dir);

    return 0;
}
