#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
    };
     
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp = head;
    
    while (temp != NULL && temp->next != NULL) {
        if (temp->val == temp->next->val) {
            struct ListNode* rem = temp->next;
            temp->next = temp->next->next;
            free(rem);
        } else {
            temp = temp->next;
        }
    }
    
    return head;
}

/*
Input -

head = [1,1,2,3,3]

Output - [1,2,3]
Expected - [1,2,3]
*/
