/*
Implement stack using array and perform following operations:
1. Push      2. Pop      
Properly handle overflow and underflow conditions.


Implement stack using singly LL.
Implement stack using doubly LL.
Convert prefix expression into postfix expression.
Write an function to evaluate postfix expression using stack.
Write a program using stack to check whether parenthesis are balanced?

Using stack check whether string is palindrome or not?
*/

#include <stdio.h>

void push(int *top, int n, int stack[], int data) {
    if (*top == n - 1) {
        printf("Overflow\n");
    } else {
        (*top)++;
        stack[*top] = data;
    }
}

void pop(int *top) {
    if (*top == -1) {
        printf("Underflow\n");
    } else {
        // printf("Popped element: %d\n", stack[*top]);
        (*top)--;
    }
}

void display(int top, int stack[]) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("\nYour stack list is: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int stack[n];
    int top = -1;
    int data;
    int entry;
    
    while (1) {
        printf("Enter the element (-1 to stop): ");
        scanf("%d", &data);

        if (data != -1) {
            push(&top, n, stack, data); 
        } else {
            break;
        }
    }

    display(top, stack);
    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &entry);

        switch (entry) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(&top, n, stack, data);
                break;

            case 2:
                pop(&top);
                break;

            case 3:
                display(top,stack);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        display(top,stack);
    }
    


    return 0;
}

/*
Results 

Enter the element (-1 to stop): 1
Enter the element (-1 to stop): 2
Enter the element (-1 to stop): 3
Enter the element (-1 to stop): 4
Enter the element (-1 to stop): -1

Your stack list is: 4 3 2 1 

1. Push
2. Pop
3. Exit
Enter your choice: 1
Enter the element to be pushed: 5

Your stack list is: 5 4 3 2 1 

1. Push
2. Pop
3. Exit
Enter your choice: 1
Enter the element to be pushed: 20
Overflow

Your stack list is: 5 4 3 2 1 

1. Push
2. Pop
3. Exit
Enter your choice: 3

Your stack list is: 5 4 3 2 1 

Enter the element (-1 to stop): 1
Enter the element (-1 to stop): 2
Enter the element (-1 to stop): -1

Your stack list is: 2 1 

1. Push
2. Pop
3. Exit
Enter your choice: 2

Your stack list is: 1 

1. Push
2. Pop
3. Exit
Enter your choice: 2
Stack is empty

1. Push
2. Pop
3. Exit
Enter your choice: 2
Underflow
Stack is empty

1. Push
2. Pop
3. Exit
Enter your choice: 3
Stack is empty
*/
