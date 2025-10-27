//Oblicz średnią arytmetyczną n liczb wprowadzonych przez użytkownika.

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int num = 0, n = 0;
    double avg = 0;
    printf("Podaj liczbe n (Enter - koniec wpisywania): ");

    while (scanf("%d", &num) != EOF) {
        printf("Odczytano: %d\n", num);
        n++;
        avg += num;
        printf("Podaj liczbe n (Ctrl-Z - koniec wpisywania): ");
    }
    avg /= n;
    printf("Srednia: %f\n", avg);

    return 0;
}
