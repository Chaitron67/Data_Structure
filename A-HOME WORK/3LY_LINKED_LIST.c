#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int total_node = 0;

struct Pinfo_Node {
    char name[50];
    char email[50];
    char mobile_no[10];
    struct Pinfo_Node *next;
};

struct Acc_info_Node {
    char acc_no[20];
    char acc_type[20];
    char acc_balance[50];
    struct Acc_info_Node *next;
};

struct Vinfo_Node {
    char vehicle_name[50];
    char vehicle_model_no[50];
    char vehicle_color[50];
    struct Vinfo_Node *next; 
};

struct BB_Node {
    int node_num;
    struct BB_Node *person_info;
    struct BB_Node *account_info;
    struct BB_Node *vehicle_info;
    struct BB_Node *next;
};



struct Pinfo_Node* person_info () {
    // Function to enter the person information :
    struct Pinfo_Node *nn, *pfirst, *temp;
    pfirst = NULL;
    nn = (struct Pinfo_Node *) malloc (sizeof(struct Pinfo_Node));

    printf("\nTAKING PERSON INFORMATION :- ");
    printf("\nEnter the Name : ");
    scanf("%s", nn->name);
    printf("Enter the Email-id : ");
    scanf("%s", nn->email);
    printf("Enter the Mobile No. : ");
    scanf("%s", nn->mobile_no);
    nn->next = NULL;
    printf("PERSON INFORMATION TAKEN SUCCESSFULLY !!!\n");

    if (pfirst == NULL) {
        pfirst = nn;
    }
    else {
        temp = pfirst;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }   

    return nn;
} // End of the person_info() function.

struct Acc_info_Node* account_info () {
    // Function to enter the account information :
    struct Acc_info_Node *nn, *accfirst, *temp;
    accfirst = NULL;
    nn = (struct Acc_info_Node *) malloc (sizeof(struct Acc_info_Node));

    printf("\nTAKING ACCOUNT INFORMATION :- ");
    printf("\nEnter Account No. : ");
    scanf("%s", nn->acc_no);
    printf("Enter Account Type : ");
    scanf("%s", nn->acc_type);
    printf("Enter the Account Balance : ");
    scanf("%s", nn->acc_balance);
    nn->next = NULL;
    printf("ACCOUNT INFORMATION TAKEN SUCCESSFULLY !!!\n");

    if (accfirst == NULL) {
        accfirst = nn;
    }
    else {
        temp = accfirst;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }   

    return nn;
}

struct Vinfo_Node* vehicle_info () {
    // Function to enter the vehicle information :
    struct Vinfo_Node *nn, *vfirst, *temp;
    vfirst = NULL;
    nn = (struct Vinfo_Node *) malloc (sizeof(struct Vinfo_Node));

    printf("\nTAKING VEHICLE INFORMATION :- ");
    printf("\nEnter Vehicle Name : ");
    scanf("%s", nn->vehicle_name);
    printf("Enter Model No. : ");
    scanf("%s", nn->vehicle_model_no);
    printf("Enter the Vehicle Color : ");
    scanf("%s", nn->vehicle_color);
    nn->next = NULL;
    printf("VEHICLE INFORMATION TAKEN SUCCESSFULLY !!!\n");

    if (vfirst == NULL) {
        vfirst = nn;
    }
    else {
        temp = vfirst;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }   

    return nn;
}

// Essential Members Declaration : 
struct BB_Node *boss_nn, *boss_first = NULL, *temp;
void add_info () {

    boss_nn = (struct BB_Node *) malloc (sizeof(struct BB_Node));
    
    system("cls");
    printf("\nENTER PERSON INFORMATION");
    boss_nn->person_info = person_info();
    getch();
    system("cls");
    printf("\nENTER ACCOUNT INFORMATION");
    boss_nn->account_info = account_info();
    getch();
    system("cls");
    printf("\nENTER VECHILE INFORMATION");
    boss_nn->vehicle_info = vehicle_info();
    getch();
    system("cls");
    boss_nn->next = NULL;

    if (boss_first == NULL) {
        boss_first = boss_nn;
    }
    else {
        temp = boss_first;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = boss_nn;
    }

    total_node++;
    boss_nn->node_num = total_node;
}

void delete_info () {
    /* PENDING ------------------------------------->
    int node_ch;
    if (boss_first == NULL) {
        printf("\nLIST IS EMPTY, NOTHING TO DELETE HERE !!!");
        return;
    }
    else {
        system("cls");
        printf("\nNODE PRESENT IN BACKBONE LIST : %d", total_node);
        printf("\nEnter which node you want to delete : ");
        scanf("%d", &node_ch);

        temp = boss_first;
        while (temp != NULL) {
            if (temp->node_num == node_ch) {
                break;
            }
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("\nNODE IS NOT PRESENT !!!");
            return;
        }
        else {
            if (temp == boss_first) {
                boss
            }
        }
    }
    */
}

void display () {
    system("cls");
    int node_ch;
    if (boss_first == NULL) {
        printf("\nLIST IS EMPTY NOTHING TO DISPLAY !!!");  
    }
    else {
        printf("\nNODE PRESENT IN BACKBONE LIST : %d", total_node);
        printf("\nEnter which node number you want to display : ");
        scanf("%d", &node_ch);
        temp = boss_first;
        while (temp != NULL) {
            if (temp->node_num == node_ch) {
                break;
            }
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("\nNODE IS NOT PRESENT !!!");
            return;
        }

        // Displaying the Node : 
        printf("\n************ Displaying Node No. %d ************\n", node_ch);
        printf("\nName : %s", (temp->person_info));
        printf("\nAccount No. : %s", (temp->account_info));
        printf("\nVehicle Name : %s", (temp->vehicle_info));
    }
}

int main () {

    int ch;

    do {
        system("cls");

        printf("\nMAIN MENU\n");
        printf("\n1. ADD INFORMATION.");
        printf("\n2. DELETE INFORMATION.");
        printf("\n3. DISPLAY INFORMATION.\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1 : // Adding the information
                add_info();
                break;

            case 2 : // Delete information 
                delete_info();
                break;

            case 3 : // Display information
                display();
                break;

            case 4 : // Exit
                exit(0);

            default : 
                printf("\nINCORRECT CHOICE, PLEASE ENTER THE CORRECT CHOICE !!!");
        }
        getch();
    }while (1);

}