/*
  Input - 1,2,3,4,5,6,7,8
  Output - 1,8,2,7,3,6,4,5

  */

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = slow->next;
    slow->next = NULL;

    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode* track = head;
    struct ListNode* temp = prev;

    while (temp != NULL) {
        struct ListNode* next1 = track->next;
        struct ListNode* next2 = temp->next;

        track->next = temp;
        temp->next = next1;

        track = next1;
        temp = next2;
    }
}
