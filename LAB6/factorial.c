#include <limits.h>
#include <stdio.h>

long long iterFac(long long i) {
    long long fac = 1;
    while (i > 1) {
        fac = fac * i;
        i --;
    }
    return fac;
}

long long recFac(long long i) {
    return  i > 1 ? recFac(i - 1) * i : 1;;
}

int main(void) {
    long long n = 1;
    printf("Enter a number: ");
    if (!scanf("%lld", &n) && n != 0) {
        printf("Error\n");
        return 0;
    }
    long long iterVal = iterFac(n), recVal = recFac(n);
    if (iterVal <= 0 || recVal<=0) {
        printf("Long long overflow\n");
        return 0;
    }
    printf("Silnia: max \t%lld\n"
           "Iteracyjna: \t%lld\n"
           "Rekurencyjna: \t%lld\n",LONG_LONG_MAX,iterVal,recVal);
}
