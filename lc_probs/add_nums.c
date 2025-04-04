#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct ListNode {
    int val;
    struct ListNode *next;
    };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode* head = NULL;
    int carry = 0;



    while (temp1 != NULL || temp2 != NULL || carry) {
        int sum = carry;

        if (temp1 != NULL) {
            sum += temp1->val;
            temp1 = temp1->next;
        }

        if (temp2 != NULL) {
            sum += temp2->val;
            temp2 = temp2->next;
        }

        carry = sum / 10;
        head = append(head, sum % 10);
    }

    return head;
}

/*
Input -

l1 = [9,9,9,9,9,9,9]
l2 = [9,9,9,9]

Output - [8,9,9,9,0,0,0,1]
Expected - [8,9,9,9,0,0,0,1]
*/