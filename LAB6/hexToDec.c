#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int hextoVal(char c) {
    int a = 0;
    switch (tolower(c)) {
        case '1':
            a = 1;
            break;
        case '2':
            a = 2;
            break;
        case '3':
            a = 3;
            break;
        case '4':
            a = 4;
            break;
        case '5':
            a = 5;
            break;
        case '6':
            a = 6;
            break;
        case '7':
            a = 7;
            break;
        case '8':
            a = 8;
            break;
        case '9':
            a = 9;
            break;
        case 'a':
            a = 10;
            break;
        case 'b':
            a = 11;
            break;
        case 'c':
            a = 12;
            break;
        case 'd':
            a = 13;
            break;
        case 'e':
            a = 14;
            break;
        case 'f':
            a = 15;
            break;
        default:
            a = 0;
    }
    return a;
}

long long hexToDec(char * hex) {
    int len = strlen(hex);
    long long val = hextoVal(hex[0]);
    for (int i = 0; i < len-1; i++){
        int a1 = hextoVal(hex[i+1]);
        if (a1 == 0)
            return 0;
        val = (val * 16) + a1;
    }
    return val;
}

int main() {
    char hex[256] = {0};
    printf("Enter hex: ");
    if (!scanf("%s",hex)) {
        printf("Invalid input\n");
        return 0;
    }


    bool run = true;
    while (run) {
        if (hex[0] == ' ' || hex[0] == '-' || hex[0] == '+' || hex[0] == '0' || hex[0] == 'x' || hex[0] == 'X') {
            memmove(hex, hex+1, strlen(hex));
            continue;
        }
        run = false;
    }
    printf("Clear hex: %s\n", hex);
    long long val = hexToDec(hex);
    if (val == 0) {
        printf("Unknown char or empty input\n");
        return 0;
    }
    printf("Decimal: %lld\n", val == 0 ? -1 : val);
}
