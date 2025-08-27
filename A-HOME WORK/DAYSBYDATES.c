#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main () {
    system("cls");
    
    int day, month;
    int day_in_month, day_in_month2, mday, mday2;
    int fday, sday, fmonth, smonth;

    int arr_month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    

    printf("YEAR : 2024");

    printf("\nENTER FIRST DATE : ");
    printf("\nDAY (DD) : ");
    scanf("%d", &day);
    fday = day;

    printf("MONTH (MM) : ");
    scanf("%d", &month);
    fmonth = month;

    for (int i=0; i<12; i++) {
        if (fmonth == i) {
            mday = arr_month[i-1];
        }
    }
    
    printf("\nENTER SECOND DATE : ");
    printf("\nDAY (DD) : ");
    scanf("%d", &day);
    sday = day;

    printf("MONTH (MM) : ");
    scanf("%d", &month);
    smonth = month;

    for (int i=0; i<12; i++) {
        if (smonth == i) {
            mday2 = arr_month[i-1];
        }
    }

    int start_month = fmonth+1;
    int end_month = smonth-1;
    int total_days = 0;

    for (int i = start_month-1; i<=end_month-1; i++) {
        total_days = total_days +  arr_month[i];
    }

    day_in_month = (mday-fday)+1;
    day_in_month2 = sday;

    total_days = total_days + (day_in_month + day_in_month2);

    printf("\nTOTAL DAYS BETWEEN THE DATES : %ddays", total_days);

    getch();
}