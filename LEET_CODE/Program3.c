#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *addBinary(char *a, char *b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int n = (alen > blen ? alen : blen) + 1; // +1 for possible carry
    char *res = (char *)malloc(n + 1);       // +1 for '\0'
    res[n] = '\0'; // null terminator

    int i = alen - 1, j = blen - 1, k = n - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        res[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // If result starts with '0', shift it
    if (res[0] == '0') {
        return res + 1; // skip leading zero
    }
    return res;
}

int main() {
    char a[] = "0";
    char b[] = "01";

    char *result = addBinary(a, b);
    printf("Addition is : %s\n", result);
    return 0;
}
