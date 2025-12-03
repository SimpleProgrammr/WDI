#include <stdio.h>

int main() {
    FILE* data = fopen("temperatures.txt", "r");
    if (data == NULL) {
        printf("Error opening temperatures.txt\n");
        return 1;
    }
    FILE* binTemp = fopen("temp.bin", "wb");
    if (binTemp == NULL) {
        printf("Error opening temp.bin\n");
        return 1;
    }

    while (1) {
        double temp = 0;
        fscanf(data, "%lf", &temp);
        if (feof(data))
            break;
        fwrite(&temp, sizeof(double), 1, binTemp);
    }
    fclose(binTemp);
    fclose(data);


    data = fopen("temp.bin", "rb");
    if (data == NULL) {
        printf("Error opening temp.bin\n");
        return 1;
    }
    int probes = 0;
    double avgTemp = 0, minTemp = 99999999, maxTemp = -9999999;
    while (1) {
        double temp = 0;
        fread(&temp, sizeof(double), 1, data);
        if (feof(data))
            break;
        printf("%d. %lf\n",probes+1, temp);
        if (temp < minTemp) minTemp = temp;
        if (temp > maxTemp) maxTemp = temp;
        probes++;
        avgTemp += temp;
    }
    avgTemp /= probes;
    fclose(data);
    printf("Temperatures avg: %.2f\n", avgTemp);
    printf("Temperatures min: %.2f\n", minTemp);
    printf("Temperatures max: %.2f\n", maxTemp);
    return 0;
}
