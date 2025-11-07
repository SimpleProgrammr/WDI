
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 0;
    if (argc < 2) {
        printf("Podaj liczbę całkowitą nie ujemną: ");
    if (scanf("%d",&n) != 1) {
        printf("Input error!");
        return -1;
    }
    }
    else {
        n = atoi(argv[1]);
    }


    if (n <= 0) {
        if (n == 0) {
            printf("BIN: 0000");
            return 0;
        }
        printf("Input error!");
    }

    int size = round(log2((double)n));
    int tab[size];
    for (int i = size; i >= 0; i--) {
        tab[i] = n%2;
        n /= 2;
    }
    printf("%d",tab[0]);
    for (int i = 1; i <= size; i++) {
        printf("%d", tab[i]);
    }

}
