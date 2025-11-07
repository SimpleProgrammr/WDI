#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double n = 0;
    if (argc < 2) {
        printf("Podaj liczbę ułamkową < 1 nie ujemną: ");
    if (scanf("%le",&n) != 1) {
        printf("Input error!");
        return -1;
    }
    }
    else {
        _atodbl(&n,argv[1]);
    }
if (n == 0) {
            printf("BIN: 0000");
            return 0;
        }

    if (n >= 1) {
        printf("Input error!");
    }

    printf("Bin: 0.");

    short i = 0;
    while (n != 0 && i < 8) {
        double n2 = n * 2;
        if (n2 >= 1) {
            printf("1");
            n*=2;
            n--;
            i++;
            continue;
        }
        printf("0");
        n*=2;
        i++;

    }

    return 0;

}
