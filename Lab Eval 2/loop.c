#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackNode {
    int data;
    struct StackNode *next;
};

void push(struct StackNode** top, int data) {
    struct StackNode* new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

void pop(struct StackNode** top) {
    if (*top != NULL) {
        struct StackNode* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int address_of_head(struct ListNode *head) {
    return (int)head;
}

bool hasCycle(struct ListNode *head) {
    struct StackNode* stack = NULL;
    struct ListNode* temp = head;

    while (temp != NULL) {
        int data = address_of_head(temp);
        
        struct StackNode* current = stack;
        while (current != NULL) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        
        push(&stack, data);
        temp = temp->next;
    }

    while (stack != NULL) {
        pop(&stack);
    }

    return false;
}