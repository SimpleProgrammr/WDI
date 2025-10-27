//(Dla chętnych) Napisz program, który wypisze tabliczkę mnożenia 1–10 w formie tabeli

#include <stdio.h>

int main(void) {
    printf("Tabliczka mnozenia: \n\t");
    for (int i = 1; i <= 10; i++) {
        printf("%d\t",i);
    }
    printf("\n\t");
    for (int i = 1; i <= 19; i++) {
        printf("----");
    }
    printf("\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d\t|", i);
        for (int j = 1; j <= 10; j++) {
            printf("%d\t",i*j);
        }
        printf("\n");
    }
    return 0;
}
