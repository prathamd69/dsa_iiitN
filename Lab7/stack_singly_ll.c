#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** top, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Stack Overflow\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = *top;
    *top = new_node;
    printf("\nPushed: %d", new_data);
}

void pop(struct node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp = *top;
    printf("\nPopped: %d", temp->data);
    *top = (*top)->next;
    free(temp);
}

void display(struct node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n\n");
}

int main() {
    struct node* stack_top = NULL; 
    int entry, value;
    
    while (1) {
        printf("1. Push");
        printf("\n2. Pop");
        printf("\n3. Exit");
        printf("\nEnter your entry: ");
        scanf("%d", &entry);

        switch (entry) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack_top, value);
                break;
                
            case 2:
                pop(&stack_top);
                break;
                
            case 3:
                display(stack_top);
                return 0;

            default:
                printf("Invalid entry. Please try again.\n");
                return 0;
        }
        printf("\n");
        display(stack_top);
    }

    return 0;
}

/*
Results 

1. Push
2. Pop
3. Exit
Enter your entry: 1
Enter the value to push: 10

Pushed: 10
Stack: 10 

1. Push
2. Pop
3. Exit
Enter your entry: 1
Enter the value to push: 20

Pushed: 20
Stack: 20 10 

1. Push
2. Pop
3. Exit
Enter your entry: 1
Enter the value to push: 30

Pushed: 30
Stack: 30 20 10 

1. Push
2. Pop
3. Exit
Enter your entry: 2

Popped: 30
Stack: 20 10 

1. Push
2. Pop
3. Exit
Enter your entry: 2

Popped: 20
Stack: 10 

1. Push
2. Pop
3. Exit
Enter your entry: 2

Popped: 10
Stack is empty
1. Push
2. Pop
3. Exit
Enter your entry: 2
Stack Underflow

Stack is empty
1. Push
2. Pop
3. Exit
Enter your entry: 3
Stack is empty
*/
