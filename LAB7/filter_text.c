#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: filter_text <input_file> <output_file> <max_value>\n");
        exit(1);
    }
    FILE *data = fopen(argv[1], "r");
    if (data == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(1);
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(1);
    }
    float limit = strtof(argv[3], NULL);
    int count = 0;
    while (1) {
        double temp = 0;
        fscanf(data, "%lf", &temp);
        if (feof(data))
            break;
        if (temp < limit)
            continue;

        fprintf(output, "%lf\n", temp);
        count++;

    }
    printf("Succeeded on %d\n", count);

    fclose(data);
    fclose(output);
    return 0;

}
