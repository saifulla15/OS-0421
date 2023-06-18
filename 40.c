#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char *file_path = "example_file.txt";

    // Check file access permissions for owner, group, and others
    struct stat file_stat;
    if (stat(file_path, &file_stat) != -1) {
        printf("File Access Permissions:\n");
        printf("Owner: ");
        printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
        printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
        printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
        printf("\n");
        printf("Group: ");
        printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
        printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
        printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
        printf("\n");
        printf("Others: ");
        printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
        printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
        printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");
    } else {
        printf("Error retrieving file information.\n");
        return 1;
    }

    // Check the type of user (owner, group, or others)
    uid_t user_id = getuid();
    gid_t group_id = getgid();

    printf("\nUser Types:\n");
    if (user_id == file_stat.st_uid) {
        printf("You are the owner of the file.\n");
    } else if (group_id == file_stat.st_gid) {
        printf("You belong to the group associated with the file.\n");
    } else {
        printf("You are an ordinary user (others).\n");
    }

    return 0;
}
