#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to insert a node at the end of the linked list
void insert(struct node** head_ref, int new_data) {
    // Create a new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    // Ensure memory allocation was successful
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Put the data in the new node
    new_node->data = new_data;

    // Make the new node the last node (next of it = NULL)
    new_node->next = NULL;

    // If the linked list is empty, make the new node as the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse the existing list to find the last node
    struct node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of the last node to new node
    last->next = new_node;
}

// Function to print the contents of the linked list
void printList(struct node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");  // Add a newline at the end
}

int main() {
    struct node* head = NULL; // Initialize head as NULL

    int choice = 0;

    printf("\n\n*********Main Menu*********\n");
    printf("\nChoose either you want to enter or exit\n");
    printf("\n===============================================\n");
    printf("\n1. Insert at last\n2. Exit\n");
    printf("\nEnter your choice: ");

    while (scanf("%d", &choice) == 1 && choice != 2) {
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                int data;
                if (scanf("%d", &data) == 1) {
                    insert(&head, data);
                    printf("Created Linked List is: ");
                    printList(head);
                } else {
                    printf("Invalid input for data. Please enter an integer.\n");
                    // Clear the input buffer to avoid issues in the next iteration
                    scanf("%*[^\n]"); // Consume remaining characters in the input stream
                }
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
        printf("\nEnter your choice: ");
    }

    printf("Exiting...\n");
    return 0;
}
