//Napisz program obliczający silnię liczby n (wczytanej z klawiatury).

#include <stdio.h>

int main(void) {
    int sum = 1, n = 0;

    printf("Podaj liczbe n(>0): ");
    int ret = scanf("%d", &n);
    if (ret != 1) {
        printf("Bledna wartosc\n");
    }

    for (int i = 1; i <= n; i++) {
        sum *= i;
    }
    printf("Silnia = %d\n", sum);
    return 0;
}
