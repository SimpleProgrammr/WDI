#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "IO.c"
void ERROR(char *msg, int code);


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
void freeNodes(Node*);
static Node *head = NULL;

Node *AddPackage(Node *HEAD) {
    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        ERROR("AddPackage(): malloc failed", 1);
    }

    newNode->package.id = getPackageID();
    newNode->package.weight = getPackegeWeight();
    getPackegeAddress(newNode->package.address);
    getPackageStatus(newNode->package.status);

    newNode->next = HEAD;
    HEAD = newNode;

    return HEAD;
}

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

void ERROR(char * msg, int code) {
    printf("%s\n", msg);
    exit(code);
}

void freeNodes(Node * HEAD) {
    if (HEAD->next != NULL) {
        freeNodes(HEAD->next);
    }
    printf("Free: %d\n", HEAD->package.id);
    free(HEAD);
}