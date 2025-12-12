#include <stdio.h>

extern void ERROR(char *msg, int code);
extern void PostErrorMsg(char *msg);

void clearBuffor() {
    fflush(stdin);
}
void clearNL(char * txt) {
    for (int i = 0; txt[i] != '\0'; i++) {
        if (txt[i] == '\n')
            txt[i] = '\0';
    }
}

int getPackageID() {
    printf("Enter package ID: ");
    int packageID = 0;
    scanf("%d%*c", &packageID);
    if(packageID == 0)
        ERROR("Wrong ID provided",1);

    return packageID;
}

double getPackageWeight() {
    printf("Enter package weight(Kg): ");
    double packageWeight = 0;
    scanf("%lf%*c",&packageWeight);
    if(packageWeight == 0)
        ERROR("Wrong weight provided",1);
    return packageWeight;
}

void getPackageAddress(char *address) {
    printf("Enter package address: ");
    fgets(address, 99, stdin);
    clearNL(address);
    clearBuffor();
}

void getPackageStatus(char *status) {
    printf("Enter package status: ");
    fgets(status, 19, stdin);
    clearNL(status);
    clearBuffor();
}

