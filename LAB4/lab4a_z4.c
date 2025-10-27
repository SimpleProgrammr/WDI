//Wypisz liczby parzyste z zakresu [0, 20] używając pętli while

#include <stdio.h>

int main(void) {
    int num = 0;

    while (num <=20) {
        if (num % 2 == 0) {
            printf("%d\n", num);
        }
        num++;
    }
    return 0;
}
