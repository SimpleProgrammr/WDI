#include <stdio.h>
#include <stdlib.h>


void ERROR(char * msg, int code) {
    fprintf(stderr, "%s\n", msg);
    exit(code);
}

void PostErrorMsg(char * msg) {
    fprintf(stderr, "%s\n", msg);
}