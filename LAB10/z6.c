#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>
#include <sys/unistd.h>
#include <sys/stat.h>

void getFilePermissions(char* filepath) {
    // Check read access
    int returnval = 0;
    returnval = access (filepath, R_OK);
    if (returnval == 0)
        printf ("%s has Read permissions.\n", filepath);
    else
    {
        if (errno == ENOENT)
            printf ("%s No such file or directory.\n", filepath);
        else if (errno == EACCES)
            printf ("%s Read Permission denied.\n", filepath);
    }
    // Check write access
    returnval = 0;
    returnval = access (filepath, W_OK);
    if (returnval == 0)
        printf ("%s has Write permissions.\n", filepath);
    else
    {
        if (errno == ENOENT)
            printf ("%s No such file or directory.\n", filepath);
        else if (errno == EACCES)
            printf ("%s Write Permission denied.\n", filepath);
    }
    // Check execute access
    returnval = 0;
    returnval = access (filepath, X_OK);
    if (returnval == 0)
        printf ("\n%s has Execute permissions.!\n", filepath);
    else
    {
        if (errno == ENOENT)
            printf ("%s No such file or directory.\n", filepath);
        else if (errno == EACCES)
            printf ("%s Doesn't have execution permissions.\n", filepath);
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("No arguments present!\n");
        return 1;
    }
    if (argc != 2) {
        printf("Too many arguments!\n");
        return 1;
    }
    if (access(argv[1], F_OK) != 0) {
        printf("No such file or directory: %s\n", argv[1]);
    }
    getFilePermissions(argv[1]);
}