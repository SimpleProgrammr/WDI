//Oblicz sumę liczb od 1 do 100 i wyświetl wynik

#include <stdio.h>

int main(void) {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("Suma = %d\n", sum);
    return 0;
}
