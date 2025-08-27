#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int sort (int pqueue[], int FRONT, int REAR) {
    int i, j, temp;
    for (i = FRONT; i<=REAR-1; i++) {
        for (j = i+1; j<=(REAR-1)-1; j++) {
            if (pqueue[i] > pqueue[i+1]) {
                temp = pqueue[i];
                pqueue[i] = pqueue[i+1];
                pqueue[i+1] = temp;
            }
        }
    } 
}

int main () {
    int pqueue[100], size, i, ch, ele;

    printf("Enter the size of the Priority Queue : ");
    scanf("%d", &size);

    int FRONT = 0, REAR = -1;

    do {
        printf("\n*SELECT OPERATIONS*");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 :
                if (FRONT == (REAR+1) % size  && REAR != -1) {
                    printf("\nPriority Queue Overflow");
                }
                else {
                    REAR = (REAR +1) % size;
                    printf("\nEnter the element to ENQUEUE : ");
                    scanf("%d", &ele);

                    sort (pqueue, FRONT, REAR);
                    printf("\nElement is ENQUEUED");
                }
                break;
            
            case 2 :
                if (FRONT == 0 && REAR == -1) {
                    printf("\nPRIORITY QUEUE UNDERFLOW");
                }
                else {
                    ele = pqueue[FRONT];
                    printf("\n%d element is DEQUEUED", ele);
                    FRONT = (FRONT + 1) % size;
                    
                    if (FRONT = (REAR +1) % size) {
                        REAR = -1;
                        FRONT = 0;
                    }
                }
                break;

            case 3 :
                if (FRONT == 0 && REAR == -1) {
                    printf("\npRIORITY QUEUE IS EMPTY, NOTHING TO DISPLAY");
                }
                else {
                    i = FRONT;
                    printf("\nPRIORITY QUEUE CONTAINS : ");
                    do {
                        printf("%d ", pqueue[i]);
                        i = (i+1) % size;
                    }while (i = (REAR +1) % size);
                }
                break;

            case 4 :
                exit(0);

            default :
                printf("\nINCORRECT CHOICE !!!");
        }
    } while (1);
}