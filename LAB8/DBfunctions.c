#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern double getPackageWeight();
extern int getPackageID();
extern void ERROR(char*, int);
extern void PostErrorMsg(char*);
extern void getPackageAddress(char * str);
extern void getPackageStatus(char*);


typedef struct {
    int id;
    double weight;
    char status[20];
    char address[100];
} PACKAGE;

typedef struct Node {
    PACKAGE package;
    struct Node *next;
}Node ;

static Node *main_head = NULL;

Node * findPackage(Node * HEAD, int id) {
    if (HEAD == NULL) {
        PostErrorMsg("No package registerted!\n");
        return NULL;
    }
    if (HEAD->package.id == id) {
        return HEAD;
    }
    if (HEAD->next != NULL) {
        Node * temp = findPackage(HEAD->next, id);
        if ( temp != NULL) {
            return temp;
        }
    }
    return NULL;
}

Node * findPackageNoLog(Node * HEAD, int id) {
    if (HEAD == NULL) {
        return NULL;
    }
    if (HEAD->package.id == id) {
        return HEAD;
    }
    if (HEAD->next != NULL) {
        Node * temp = findPackage(HEAD->next, id);
        if ( temp != NULL) {
            return temp;
        }
    }
    return NULL;
}

Node *addPackage(Node *HEAD) {
    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        ERROR("Memory allocation error",1);
    }
    while (1) {
        newNode->package.id = getPackageID();
        if (findPackageNoLog(HEAD, newNode->package.id) != NULL) {
            printf("Package with this ID already exist.\n");
            continue;
        }
        break;
    }
    newNode->package.weight = getPackageWeight();
    getPackageAddress(newNode->package.address);
    getPackageStatus(newNode->package.status);

    newNode->next = HEAD;
    HEAD = newNode;

    return HEAD;
}

void freeNodes(Node * HEAD) {
    if (HEAD->next != NULL) {
        freeNodes(HEAD->next);
    }
    printf("Free: %d\n", HEAD->package.id);
    free(HEAD);
}

void printPackageInfo(Node * HEAD) {
    if (HEAD == NULL) {
        PostErrorMsg("No such package in system!\n");
    }
    printf("---------------------------------------------------\n");
    printf("Package ID: %d\n", HEAD->package.id);
    printf("Package Weight: %f\n", HEAD->package.weight);
    printf("Package Address: %s\n", HEAD->package.address);
    printf("Package Status: %s\n\n", HEAD->package.status);
}

void printAllPackages(Node * HEAD) {
    if (HEAD->next != NULL) {
        printAllPackages(HEAD->next);
    }
    printPackageInfo(HEAD);
}

Node * removePackage(Node * HEAD, int id) {
    if (HEAD == NULL) {
        PostErrorMsg("No package in system!\n");
        return NULL;
    }
    if (HEAD->package.id == id) {
        Node * temp = HEAD;
        HEAD = HEAD->next;
        free(temp);
        printf("Package %d removed.\n", id);
        return HEAD;
    }if (HEAD->next != NULL) {
        HEAD->next = removePackage(HEAD->next, id);
    }
    return HEAD;
}

void updatePackageStatus(Node * HEAD) {
    if (HEAD == NULL) {
        PostErrorMsg("No such package in system!\n");
        return;
    }
    getPackageStatus(HEAD->package.status);
    printAllPackages(main_head);
}

void getShippingRaport(Node * HEAD) {
    static char pTop = 't';
    pTop = 't';
    if (HEAD == NULL) {
        PostErrorMsg("No such package in system!\n");
        return;
    }
    static int in_shipping = 0;
    if (strcmp(HEAD->package.status, "shipping") == 0) {
        in_shipping ++;
    }
    if (HEAD->next != NULL) {
        getShippingRaport(HEAD->next);
    }

    if (pTop == 't') {
        printf("--------------------Shipping: %d--------------------\n", in_shipping);
        pTop = 'f';
    }
    if (strcmp(HEAD->package.status, "shipping") == 0)
        printPackageInfo(HEAD);
    in_shipping = 0;
}