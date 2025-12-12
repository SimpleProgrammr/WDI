#include <stdbool.h>
#include "DBfunctions.c"
#include "errorHandler.c"
#include "IO.c"

Node * debugAdd(Node* HEAD, int id, double weight) {
    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        ERROR("Memory allocation error",1);
    }
    newNode->package.id = id;
    newNode->package.weight = weight;

    newNode->next = HEAD;
    HEAD = newNode;

    return HEAD;
}


int main() {

    main_head = debugAdd(main_head, 1, 1);
    main_head = debugAdd(main_head, 2, 0);
    main_head = debugAdd(main_head, 3, -1);
    main_head = debugAdd(main_head, 4, -2);
    main_head = debugAdd(main_head, 5, -3);

    bool run = true;
    while (run) {
        system("clear");
        printf("1. AddPackage()\n");
        printf("2. FindPackageByID()\n");
        printf("3. RemovePackageByID()\n");
        printf("4. UpdatePackageStatus()\n");
        printf("5. GetShippingRaport()\n");
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
            case '0':
                run = false;
                break;
            default:
                break;
        }
    }

    freeNodes(main_head);
}
