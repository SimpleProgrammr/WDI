
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Arguments error!");
        return -1;
    }

    if (strlen(argv[1]) < 1) {
        printf("Input error!");
        return -1;
    }

    int val= 0;
    for (int i = 0; i < strlen(argv[1]); i++) {
        const char ch = argv[1][i];
        if (ch != '0' && ch != '1') {
            printf("Characters error!");
            return -1;
        }


        val += (ch - 48)*pow(2, strlen(argv[1]) - i - 1);
    }
    printf("%s -> %d\n", argv[1], val);

}
