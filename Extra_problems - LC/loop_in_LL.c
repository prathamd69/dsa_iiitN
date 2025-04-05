#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
void push(int **stack, int *top, int data) {
    *top += 1;
    *stack = realloc(*stack, (*top + 1) * sizeof(int));
    (*stack)[*top] = data;
}

void pop(int **stack, int *top) {
    if (*top >= 0) {
        *top -= 1;
        *stack = realloc(*stack, (*top + 1) * sizeof(int));
    }
}

int address_of_head(struct ListNode *head) {
    return (int)head;
}

bool hasCycle(struct ListNode *head) {
    int *stack = NULL;
    int top = -1;
    struct ListNode* temp = head;

    while (temp != NULL) {
        int data = address_of_head(temp);

        for (int i = 0; i <= top; i++) {
            if (stack[i] == data) {
                free(stack);
                return true;
            }
        }

        push(&stack, &top, data);
        temp = temp->next;
    }

    free(stack);
    return false;
}

/*
Input -
head = [3,2,0,-4]
pos = 1

Output - true
Expected - true
*/