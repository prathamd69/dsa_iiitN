#include <stdio.h>
#define MAX_SIZE 100

void push(int *top, int n, char stack[], char data) {
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
        (*top)--;
    }
}

int main() {
    char data;
    char stack[MAX_SIZE];
    int top = -1;
    int n = MAX_SIZE;

    while (1) {
        printf("Enter next char (or 'q' to quit): ");
        scanf(" %c", &data);

        if (data == 'q') {
            break;
        } else if (data == '(') {
            push(&top, n, stack, data);
        } else if (data == ')') {
            if (top == -1) {
                printf("False\n");
                return 0;
            }
            pop(&top);
        }
    }

    if (top == -1) {
        printf("True\n");
    } else {
        printf("False\n"); 
    }

    return 0;
}
