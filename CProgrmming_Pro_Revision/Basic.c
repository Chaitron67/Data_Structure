#include <stdio.h>
#include <string.h>

int main() {
    char *name[2];

    printf("Enter your name : ");
    scanf("%s", &name[1]);

    printf("%s", name[1]);

    return 0;
}