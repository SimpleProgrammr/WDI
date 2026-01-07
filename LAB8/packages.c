#include <stdbool.h>
#include <stdlib.h>
#include "DBfunctions.c"
#include "errorHandler.c"
#include "IO.c"

NODE * debugAdd(NODE* HEAD, int id, double weight) {
    NODE *newNode = calloc(1, sizeof(NODE));
    if (newNode == NULL) {
        ERROR("Memory allocation error",1);
    }
    newNode->package.id = id;
    newNode->package.weight = weight;
    memcpy(newNode->package.address, "Fuck off", 100*sizeof(char));
    memcpy(newNode->package.status, "Bitch", 20*sizeof(char));

    newNode->next = HEAD;
    HEAD = newNode;

    return HEAD;
}

int cli_main() {
    while (1) {
        system("clear");
        printf("1. AddPackage()\n");
        printf("2. FindPackageByID()\n");
        printf("3. RemovePackageByID()\n");
        printf("4. UpdatePackageStatus()\n");
        printf("5. GetShippingRaport()\n");
        printf("6. PrintAllPackages()\n");
        printf("0. Exit\n");

        char c = getc(stdin);
        switch (c) {
            case '1':
                main_head = addPackage(main_head);
                break;
            case '2':
                printPackageInfo(findPackage(main_head, getPackageID()));
                break;
            case '3':
                main_head = removePackage(main_head, getPackageID());
                printAllPackages(main_head);
                break;
            case '4':
                updatePackageStatus(findPackage(main_head, getPackageID()));
                break;
            case '5':
                getShippingRaport(main_head);
                break;
            case '6':
                printAllPackages(main_head);
                break;
            case '0':
                freeNodes(main_head);
                exit(0);
            default:
                break;
        }

        printf("Click ENTER to continue...\n");
        getchar();
    }

}

int main() {
    cli_main();
}
