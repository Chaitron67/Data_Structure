#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main () {
    int stack[10];
    int i, ch, ele, ptop = 5, stop = 4;
    char ch2, ch3;

    do {
        system("cls");

        printf("\n*************MAIN MENU*************");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 :
                if (ptop == 0) {
                    printf("\nPRIMARY STACK OVERFLOW !!!");
                }
                else {
                    printf("\nEnter the element to PUSH : ");
                    scanf("%d", &ele);
                    stack[ptop-1] = ele;
                    ptop--;
                    printf("\n%d ELEMENT IS PUSHED INTO THE PRIMARY STACK !!!", ele);
                }
                break;

            case 2 :
                printf("\nIN WHICH STACK DO YOU WANT TO PERFORM POP OPERATION");
                printf("\nP - PRIMARY STACK");
                printf("\nS - SECONDARY STACK");
                
                printf("\nEnter your choice : ");
                scanf("%s", &ch2);

                switch (ch2) {
                    case 'P' :
                        if (ptop == 5) {
                            printf("\nPRIMARY STACK UNDERFLOW !!!");
                            printf("\nCAN'T PERFORM POP OPERATION !!!");
                        }
                        else {
                            if (stop == 9) {
                                printf("\nSECONDARY STACK IS FULL !!!\nWE CAN'T PERFORM POP OPERATION IN PRIMARY STACK !!!");
                            }
                            else {
                                ele = stack[ptop];
                                ptop++;
                                stack[stop+1] = ele;
                                stop++;
                                printf("\n%d ELEMENT IS POPPED OUT FROM PRIMARY STACK \nAND PUSHED INTO SECONDARY STACK !!!", ele);
                            }
                        }
                        break;

                    case 'S' :
                        system("cls");
                        printf("\n*************SECONDARY STACK POP OPERATION MENU*************");
                        printf("\nR - RESTORE");
                        printf("\nD - DISCARD");

                        printf("\nEnter your choice : ");
                        scanf("%s", &ch3);

                        switch (ch3) {
                            case 'R' :
                                if (stop == 4) {
                                    printf("\nSECONDARY STACK UNDERFLOW\nNOTHING TO RESTORE !!!");
                                }
                                else {
                                    if (ptop == 0) {
                                        printf("\nPRIMARY STACK OVERFLOW \nCANNOT RESTORE THE ELEMENT IN PRIMARY STACK !!!");
                                    }
                                    else {
                                        ele = stack[stop];
                                        stop--;
                                        stack[ptop-1] = ele;
                                        ptop--;
                                        printf("\n%d ELEMENT IS RESTORED FROM SECONDARY TO PRIMARY STACK !!!", ele);
                                    }
                                }
                                break;

                            case 'D' :
                                if (stop == 4) {
                                    printf("\nSECONDARY STACK UNDERFLOW\nNOTHING TO DISCARD !!!");
                                }
                                else {
                                    ele = stack[stop];
                                    stop--;
                                    printf("\n%d ELEMENT IS DISCARDED AND DELETED FROM THE SECONDARY STACK !!!", ele); 
                                }
                                break; 
                        }                   
                        break; // end of case 'S'
                }
                break; // end of case 2

            case 3 :
                system("cls");

                printf("\n*************DISPLAY MENU*************");
                printf("\nP - PRIMARY STACK");
                printf("\nS - SECONDARY STACK");

                printf("\nEnter which Stack do you want to Display : ");
                scanf("%s", &ch3);

                switch (ch3) {
                    case 'P' :
                        if (ptop == 5) {
                            printf("\nPRIMARY STACK UNDERFLOW\nNOTHING TO DISPLAY !!!");
                        }
                        else {
                            printf("\nPRIMARY STACK CONTAIAINS : \n");
                            for (i=ptop; i<=4; i++)
                            {
                                printf("\n  %d", stack[i]);
                            }
                        }
                        break;

                    case 'S' :
                        if (stop == 4) {
                            printf("\nSECONDARY STACK UNDERFLOW\nNOTHING TO DISPLAY !!!");
                        }
                        else {
                            printf("\nSECONDARY STACK CONTAINS : \n");
                            for (int i = stop; i >= 5; i--) {
                                printf("\n  %d", stack[i]);
                            }
                        }
                        break;
                }
                break; // end of display case 3

            case 4 :
                exit(0);

            default :
                printf("\nINCORRECT CHOICE, KINDLY ENTER A VALID CHOICE !!!");
                break;
        }
        getch();
    } while (1);
}