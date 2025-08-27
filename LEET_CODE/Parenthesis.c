#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Function declaration
bool isValid(char* s);

int main() {
    char s[10005];   // as per constraint 1 <= s.length <= 10^4

    printf("Enter the string of brackets: ");
    scanf("%s", s);

    if (isValid(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}

// Function definition (logic to be implemented by you)
bool isValid(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        printf("\n%c", s[i]);
    }

    int parenthCount = 0, curlyCount = 0, squareCount = 0;

    for (int i = 0; i < strlen(s); i++) {
        printf("\n%c", s[i]);
        if (s[i] == '(') {
            parenthCount++;
        }
        else if (s[i] == '{') {
            curlyCount++;
        }
        else if (s[i] == '[') {
            squareCount++;
        }
        else if (s[i] == ')') {
            parenthCount--;
        }
        else if (s[i] == ']') {
            squareCount--;
        }
        else if (s[i] == '}') {
            curlyCount--;
        }
        else {
            return 0;
        }
    }

    if (parenthCount == 0 && squareCount == 0 && curlyCount == 0) {
        return 1;
    }

    return 0;
}
