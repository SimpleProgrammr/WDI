#include <stdio.h>
#include <string.h>
double a[4] = {2, -3, 5, -4};

double polinominalVal(double x) {
    double val = a[0];
    for (int i = 0; i < 3; i++){

        val = (val * x) + a[i+1];
    }
    return val;
}

int main () {

    double x = 0;
    printf("Enter the x: ");
    if (!scanf("%lf",&x)) {
        printf("Invalid input\n");
        return 0;
    }
    printf("y = %lf",polinominalVal(x));

}
