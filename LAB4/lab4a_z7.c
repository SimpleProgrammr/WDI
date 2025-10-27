//Narysuj prostokąt z gwiazdek o rozmiarze n×m (użytkownik podaje n i m).

#include <stdio.h>

int main(void) {
    int n =0,m=0;

    printf("Podaj n, m(rozdzielone spacjami): ");
    int ret = scanf("%d%d", &n, &m);
    if (ret != 2) {
        printf("Bledna wartosc\n");
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}
