#include <stdio.h>
#include <stdlib.h>

char a[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void display()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", a[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}

void checkO()
{
    // First row
    if (a[0][0] == 'o' && a[0][1] == 'o' && a[0][2] == 'o')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
    // Second row
    else if (a[1][0] == 'o' && a[1][1] == 'o' && a[1][2] == 'o')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
    // Third row
    else if (a[2][0] == 'o' && a[2][1] == 'o' && a[2][2] == 'o')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
    // Diagonal
    else if (a[0][0] == 'o' && a[1][1] == 'o' && a[2][2] == 'o')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
    // Diagonal
    else if (a[0][2] == 'o' && a[1][1] == 'o' && a[2][0] == 'o')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
    // Vertical
    else if (a[0][0] == 'o' && a[1][0] == 'o' && a[2][0] == 'o')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
    // Vertical 
    else if (a[0][1] == 'o' && a[1][1] == 'o' && a[2][1] == 'o')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
    // Vertical
    else if (a[0][3] == 'o' && a[1][3] == 'o' && a[2][3] == 'o')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
}

void checkX()
{
    if (a[0][0] == 'x' && a[0][1] == 'x' && a[0][2] == 'x')
    {
        printf("PLayer 2 Win");
        exit(0);
    }
    else if (a[1][0] == 'x' && a[1][1] == 'x' && a[1][2] == 'x')
    {
        printf("PLayer 2 Win");
        exit(0);
    }
    else if (a[2][0] == 'x' && a[2][1] == 'x' && a[2][2] == 'x')
    {
        printf("PLayer 1 Win");
        exit(0);
    }
    else if (a[0][0] == 'x' && a[1][1] == 'x' && a[2][2] == 'x')
    {
        printf("PLayer 2 Win");
        exit(0);
    }
    else if (a[0][2] == 'x' && a[1][1] == 'x' && a[2][0] == 'x')
    {
        printf("PLayer 2 Win");
        exit(0);
    }
    else if (a[0][0] == 'x' && a[1][0] == 'x' && a[2][0] == 'x')
    {
        printf("PLayer 2 Win");
        exit(0);
    }
    else if (a[0][1] == 'x' && a[1][1] == 'x' && a[2][1] == 'x')
    {
        printf("PLayer 2 Win");
        exit(0);
    }
    else if (a[0][2] == 'x' && a[1][2] == 'x' && a[2][2] == 'x')
    {
        printf("PLayer 2 Win");
        exit(0);
    }
}

int isdraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3' || a[i][j] == '4' || a[i][j] == '5' || a[i][j] == '6' || a[i][j] == '7' || a[i][j] == '8' || a[i][j] == '9') {
                return 0;
            }           
        }
    }
    return 1;
}

int main()
{
    char ch;
    int f1, f2, f3, f4, f5, f6, f7, f8, f9;
    f1 = f2 = f3 = f4 = f5 = f6 = f7 = f8 = f9 = 0;
    int count = 0;

    display();

    while (1)
    {

    inputp1:
        printf("\nPlayer 1 Turn : ");
        scanf("%s", &ch);
        switch (ch)
        {
        case '1':
            if (f1 == 0)
            {
                a[0][0] = 'o';
                f1 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp1;
            }
            break;
        case '2':
            if (f2 == 0)
            {
                a[0][1] = 'o';
                f2 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp1;
            }
            break;

        case '3':
            if (f3 == 0)
            {
                a[0][2] = 'o';
                f3 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp1;
            }
            break;

        case '4':
            if (f4 == 0)
            {
                a[1][0] = 'o';
                f4 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp1;
            }
            break;

        case '5':
            if (f5 == 0)
            {
                a[1][1] = 'o';
                f5 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp1;
            }
            break;

        case '6':
            if (f6 == 0)
            {
                a[1][2] = 'o';
                f6 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp1;
            }
            break;

        case '7':
            if (f7 == 0)
            {
                a[2][0] = 'o';
                f7 = 1;
            }
            else
            {
                goto inputp1;
            }
            break;

        case '8':
            if (f8 == 0)
            {
                a[2][1] = 'o';
                f8 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp1;
            }
            break;

        case '9':
            if (f9 == 0)
            {
                a[2][2] = 'o';
                f9 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp1;
            }
            break;

        default:
            break;
        }
        count++;

        display();
        if (isdraw()) {
            printf("Match Draw !!!\n");
            exit(0);
        }
        checkO();


    inputp2:
        printf("\nPlayer 2 turn : ");
        scanf("%s", &ch);
        switch (ch)
        {
        case '1':
            if (f1 == 0)
            {
                a[0][0] = 'x';
                f1 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        case '2':
            if (f2 == 0)
            {
                a[0][1] = 'x';
                f2 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        case '3':
            if (f3 == 0)
            {
                a[0][2] = 'x';
                f3 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        case '4':
            if (f4 == 0)
            {
                a[1][0] = 'x';
                f4 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        case '5':
            if (f5 == 0)
            {
                a[1][1] = 'x';
                f5 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        case '6':
            if (f6 == 0)
            {
                a[1][2] = 'x';
                f6 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        case '7':
            if (f7 == 0)
            {
                a[2][0] = 'x';
                f7 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        case '8':
            if (f8 == 0)
            {
                a[2][1] = 'x';
                f8 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        case '9':
            if (f9 == 0)
            {
                a[2][2] = 'x';
                f9 = 1;
            }
            else
            {
                printf("Block is occupied, please re-enter the correct block ");
                goto inputp2;
            }
            break;

        default:
            break;
        }

        count++;
        display();
        checkX();
    }

    return 0;
}