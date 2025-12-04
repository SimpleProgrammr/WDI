#include <stdint.h>
#include <stdio.h>
int main() {
    FILE *temps = fopen("temperatures.txt", "r");
    FILE *raport = fopen("raport.txt", "w");

    int probes = 0;
    double avgTemp = 0, minTemp=9999999,maxTemp = -9999999;
    while (1) {
        double temp = 0;
        fscanf(temps, "%lf", &temp);
        if (feof(temps))
            break;
        printf("%d. %lf\n",probes+1, temp);
        if (temp < minTemp) minTemp = temp;
        if (temp > maxTemp) maxTemp = temp;
        probes++;
        avgTemp += temp;


    }
    avgTemp /= probes;
    fprintf(raport, "Avg temp: %.2f\n", avgTemp);
    fprintf(raport, "Min: %.2f\n", minTemp);
    fprintf(raport, "Max: %.2f\n", maxTemp);
}