//Napisz program, który wypisze sumę liczb nieparzystych do n.
#include <stdio.h>

int main(void) {
    int sum = 0, n;

    printf("Podaj n: ");
    int ret = scanf("%d", &n);
    if (ret != 1) {
        printf("Bledna wartosc\n");
    }
    
    for (int i = 1; i <= n; i++) {
        if (i%2==1)
            sum += i;
    }
    printf("Suma = %d\n", sum);
    return 0;
}
