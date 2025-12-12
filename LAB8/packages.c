#include <stdbool.h>
#include "DBfunctions.c"
#include "errorHandler.c"
#include "IO.c"


int main() {
    bool run = true;
    while (run) {
        system("clear");
        printf("1. AddPackage()\n");
        printf("2. FindPackageByID()\n");
        printf("0. Exit\n");

        char c = getchar();
        switch (c) {
            case '1':
                head = AddPackage(head);
                break;
            case '2':
                printPackageInfo(FindPackage(head, getPackageID()));
                break;
            case '0':
                run = false;
                break;
            default:
                break;
        }
    }

    freeNodes(head);
}
