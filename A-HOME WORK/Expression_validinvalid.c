#include <stdio.h>
#include <stdlib.h>

int main()
{
    char exp[50];
    int i, j, flag = -1;

    printf("Enter the exprssion : ");
    scanf("%s", &exp);

    i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '{')
        {
            int j = i;
            while (exp[j] != '\0')
            {
                if (exp[j] == '}')
                {
                    // Correct expression
                    flag = 2;
                    break;
                }
                else if (exp[j + 1] == '\0' && exp[j] != '}')
                {
                    printf("INValid Expression.");
                    goto here;
                }
                j++;
            }
        }
        else if (exp[i] == '[')
        {
            int j = i;
            while (exp[j] != '\0')
            {
                if (exp[j] == ']')
                {
                    // Correct expression
                    flag = 2;
                    break;
                }
                else if (exp[j + 1] == '\0' && exp[j] != ']')
                {
                    printf("INValid Expression.");
                    goto here;
                }
                j++;
            }
        }
        else if (exp[i] == '(')
        {
            int j = i;
            while (exp[j] != '\0')
            {
                if (exp[j] == ')')
                {
                    // Correct expression
                    flag = 2;
                    break;
                }
                else if (exp[j + 1] == '\0' && exp[j] != ')')
                {
                    printf("INValid Expression.");
                    goto here;
                }
                j++;
            }
        }

        i++;
    }

    if (flag == -1)
    {   
        here :
        exit(0);
         printf("Invalid Expression.");
    }
    else if (flag == 2)
    {
        printf("Valid Expression.");
    }

    return 0;
}