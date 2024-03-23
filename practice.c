#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node
{
    int data; // The data stored in the node
    struct node *next; // Pointer to the next node in the list
};

struct node* head = NULL; // Initialize the head of the list as NULL

// Function to insert nodes at the end of the list
void insert(struct node **head) {

    int num = 0, i, data;
    printf("\nEnter the number of elements to be inserted: ");
    scanf("%d", &num); // Get the number of nodes to be inserted

    // Loop to insert the nodes
    for(i = 0; i<num; i++) {

        // Allocate memory for a new node and get the data for it
        struct node* newNode = malloc(sizeof(struct node));
        struct node *last = *head;

        printf("\nEnter the element %d: ", i+1);
        scanf("%d", &data); // Get the data for the node

        // Initialize the new node with the given data and set its next pointer to NULL
        newNode->data  = data;
        newNode->next = NULL;

        // If the list is empty, make the new node the head of the list
        if (*head == NULL) {
            *head = newNode;
        } else {
            // If the list is not empty, traverse to the end of the list
            while (last->next != NULL) {
                last = last->next;
            }

            // Insert the new node at the end of the list
            last->next = newNode;
        }
    }
}

// Function to print the data in the list
void printList(struct node *node) {
    while (node != NULL) {
        printf(" %d ", node->data); // Print the data in the node
        node = node->next; // Move to the next node
    }
}

// Main function
void main () {
    int choice = 0;
    printf("\n\n*********Main Menu*********\n");  
    printf("\nChoose either you want to enter of exit\n");  
    printf("\n===============================================\n");  
    printf("\n1.Insert at last\n2.Exit\n");  
    printf("\nEnter your choice: ");         
    scanf("\n%d",&choice); // Get the user's choice

    // Loop to execute based on the user's choice
    while(choice != 2){
        switch(choice){
            case 1:
                // If the user chooses 1, insert nodes and print the list
                insert(&head);
                printf("Created Linked List is: ");
                printList(head);
                break;
            case 2:
                // If the user chooses 2, print the list and exit the program
                printList(head);
                exit(0);
            default:
                // If the user enters an invalid choice, print an error message
                printf("Invalid input!");
        }
    printf("\n\n*********Main Menu*********\n");  
    printf("\nChoose either you want to enter of exit\n");  
    printf("\n===============================================\n");  
    printf("\n1.Insert at last\n2.Exit\n"); 
    printf("\nEnter your choice: ");         
    scanf("\n%d",&choice); // Get the user's choice again
    }
}