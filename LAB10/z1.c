#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("No arguments present!\n");
        return 1;
    }
    printf("Lp. | arg.\n");
    for (int i = 1; i < argc; i++) {
        printf("%d  |  %s\n",i, argv[i]);
    }
    return 0;
}
