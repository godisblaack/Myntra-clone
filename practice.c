#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **head) {
    int num, i, data;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &num);
    for(i = 0; i<num; i++) {
        struct node* newNode = malloc(sizeof(struct node));
        struct node *last = *head;
        printf("Enter the element %d: ", i+1);
        scanf("%d", &data);
        newNode->data  = data;
        newNode->next = NULL;
        if (*head == NULL) {
       *head = newNode;
       return;
        }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    return;    
    }
}
void printList(struct node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}
void main () {
    int choice = 0;
    struct node* head = NULL;
    printf("\n\n*********Main Menu*********\n");  
    printf("\nChoose either you want to enter of exit\n");  
    printf("\n===============================================\n");  
    printf("\n1.Insert at last\n2.Exit\n");  
    printf("\nEnter your choice: ");         
    scanf("\n%d",&choice);  
    while(choice != 2){
        switch(choice){
            case 1: 
                insert(&head);
                printf("Created Linked List is: ");
                printList(head);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid input!");
        }
    }
}

