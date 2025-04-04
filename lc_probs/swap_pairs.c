#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
    };

struct ListNode* swapPairs(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL){
        return head;
    }

    

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    struct ListNode* prev = NULL;
    head = head->next;

    while (fast != NULL) {
        slow->next = fast->next;
        fast->next = slow;

        if (prev != NULL) {
            prev->next = fast;
        }

        prev = slow;
        slow = slow->next;
        if (slow != NULL) {
            fast = slow->next;
        } else {
            fast = NULL;
        }
    }

    return head;
}
/*
Input -

head = [1,2,3,4]

Output - [2,1,4,3]
Expected - [2,1,4,3]
*/