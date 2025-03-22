#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


void printList(struct node* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

struct node* createnode(int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); // Corrected the type declaration for 'new_node'
    new_node->data = new_data;
    new_node->next = NULL; // Ensured the next pointer is initialized to NULL
    return new_node;
}

void push(struct node** top, int data) {
    struct node* nnode = createnode(data); // Added 'struct' keyword and corrected variable declaration
    nnode->next = *top; // Link the new node to the existing list
    *top = nnode; // Update the 'top' to point to the new node
}

void pop(struct node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    
    struct node* temp = *top;
    *top = (*top)->next; // Move the top pointer to the next node
    free(temp);          // Free the memory of the removed node
}

int main() {
    struct node* top = NULL; // Pointer should be NULL initially to indicate an empty list

    push(&top, 10); 
    push(&top, 10); 
    push(&top, 10); 
    push(&top, 10); 
    push(&top, 10); 
    push(&top, 10); 
    
    printList(top); // Print the list to verify
    pop(&top);

    printf("\n\nYour entered Linked List is: ");
    printList(top); // Display the list again

    return 0;
}