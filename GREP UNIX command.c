#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    /* If no pattern is specified, print error and exit */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s pattern [file ...]\n", argv[0]);
        exit(1);
    }

    /* Get the search pattern */
    char *pattern = argv[1];

    /* If no files are specified, read from standard input */
    if (argc == 2) {
        char line[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
            if (strstr(line, pattern) != NULL) {
                printf("%s", line);
            }
        }
    } else {
        /* Read from the specified files */
        int i;
        for (i = 2; i < argc; i++) {
            FILE *fp;
            char line[MAX_LINE_LENGTH];

            /* Open the file */
            if ((fp = fopen(argv[i], "r")) == NULL) {
                perror(argv[i]);
                continue;
            }

            /* Read each line and print those that contain the search pattern */
            while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
                if (strstr(line, pattern) != NULL) {
                    printf("%s: %s", argv[i], line);
                }
            }

            /* Close the file */
            fclose(fp);
        }
    }

    return 0;
}
