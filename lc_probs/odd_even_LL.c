#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {

    if (head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* temp1 = head; 
    struct ListNode* temp2 = head->next;
    struct ListNode* head2 = head->next; 

       while (temp1->next != NULL && temp2->next != NULL) {
        temp1->next = temp1->next->next;
        temp2->next = temp2->next->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }


    temp1->next = head2;
    return head;
}

/*
Input
head = [1,2,3,4,5]
Output = [1,3,5,2,4]
Expected = [1,3,5,2,4]
*/