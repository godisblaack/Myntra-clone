#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int menu();
void display(struct node **head);
void beginsert(struct node **head);

void main () {
    
    struct node *head = NULL;

    int choice = menu();

    while(choice) {
        switch(choice) {
            case 0:
                exit(0);
                break;
            case 1:
                beginsert(&head);
                display(&head);
                break;
        }
        choice = menu();
    }
}

int menu () {
    
    int choice;
    printf("\nMain Menu");
    printf("\n0.Exit\n1.Insert at the beggining\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void display (struct node **head) {
    struct node *ptr = *head;
    if (ptr == NULL) {
        printf("\nList is empty.");
    } else {
        printf("\nValue in the linked list : ");
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr -> next;
        }
    }
}

 void beginsert (struct node **head) {
    int data;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    struct node *beg;
    
    printf("\nEnter the data: ");
    scanf("%d", &data);

    newNode -> data = data;
    newNode -> next = NULL;

    if(*head == NULL) {
        *head = newNode;
    } else {
        newNode -> next = *head;
        *head = newNode;    
    }
}