
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("No arguments present!\n");
        printf("Usage: ./z2 <add/mull>\n");
        return 1;
    }
    if (argc != 2) {
        printf("To many argument!");
        printf("Usage: ./z2 <add/mull>\n");
    }
    printf("Enter number A: ");
    int A = 0;
    scanf("%d", &A);
    printf("Enter number B: ");
    int B = 0;
    scanf("%d", &B);
    if (strcmp(argv[1], "add") == 0) {
        printf("Adding...\n");
        printf("A + B = %d", A + B );
    }
    else if (strcmp(argv[1], "mul") == 0) {
        printf("Adding...\n");
        printf("A + B = %d", A * B);
    }
    else {
        printf("No such command!\n");
    }

    return 0;
}
