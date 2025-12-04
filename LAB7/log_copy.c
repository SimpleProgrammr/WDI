

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: log_copy <src> <dst>\n");
        exit(1);
    }
    FILE *src = fopen(argv[1],"r"), *dst = fopen(argv[2],"w");
    if (src == NULL) {
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }
    if (dst == NULL) {
        printf("Can't work with %s\n", argv[2]);
        exit(1);
    }

    while (1) {
        char c = fgetc(src);
        if (c == EOF) {
            break;
        }
        printf("%c", c);
        fprintf(dst, "%c", c);
    }
    fclose(dst);
    fclose(src);
}
