#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    FILE *file1;

    file1 = fopen("file1.txt", "r");
    int ch, words;

    int i = 0, j = 0;
    char stmt[100][100];

    while (1) {
        ch = fgetc(file1);
        if (ch == EOF) {
            break;
        }

        if (ch != ' ') {
            stmt[i][j] = ch;
            j++;
        }
        else {
            stmt[i][j] = '\0';
            i++;
            j = 0;
        }
    }

    words = i+1;

    for (int x = 0; x < words; x++) {
        printf("%s\n", stmt[x]);
    }

    printf("\n");

    char temp[100];
    for (int s = 0; s < words; s++) {
        int i = s+1;
        while (i != words) {
            if (stmt[s][0] > stmt[i][0]) {
                strcpy(temp, stmt[s]);
                strcpy(stmt[s], stmt[i]);
                strcpy(stmt[i], temp);
            }
            i++;
        }
    }

    FILE *file2;
    file2 = fopen("file2.txt", "w");

    for (int x = 0; x < words; x++) {
        fprintf(file2, "%s ", stmt[x]);
        printf("%s\n", stmt[x]);
    }
}