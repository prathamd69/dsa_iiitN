#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
    };

int counter(struct ListNode* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
   return count;
}
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    int count = counter(head);

    if (k % count == 0) {
        return head;
    }


    int stepsToNewHead = count - (k % count);

    struct ListNode* temp = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        temp = temp->next;
    }


    struct ListNode* newHead = temp->next;
    temp->next = NULL;

    struct ListNode* tail = newHead;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head;

    return newHead;
}

/*
Input -

head = [1,2,3,4,5]
k = 2

Output - [4,5,1,2,3]
Expected - [4,5,1,2,3]
*/