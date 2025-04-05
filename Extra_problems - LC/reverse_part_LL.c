// reverse a particular section of a Linked List. 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
    };

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {

    if (head == NULL || left == right) {
        return head;
    }

    struct ListNode* temp = head;

    if (left == 1){
        for(int i = 1; i <right; i++){
            temp = temp ->next;
        }
        struct ListNode* add_r = temp->next;
        temp->next = NULL;
        struct ListNode* prev = reverseList(head);
        head->next = add_r;
        return temp;

    }
    for (int i = 1; i < left-1; i++) {
        temp = temp->next;
    }

    struct ListNode* add_l = temp->next;
    struct ListNode* temp2 = temp->next;

    for (int i = left; i<right; i++){
        temp2 = temp2->next;
    }

    struct ListNode* add_r = temp2->next;
    temp2->next = NULL;

    struct ListNode* prev = reverseList(add_l);
    // return prev;
    // right

    temp->next = prev;

    struct ListNode* var = prev->next;

    while(var->next != NULL){
        var = var->next;
    }

    var->next= add_r;

    return head;



}

/*
Input -

head = [1,2,3,4,5]
left = 2
right = 4

Output - [1,4,3,2,5]
Expected - [1,4,3,2,5]

*/