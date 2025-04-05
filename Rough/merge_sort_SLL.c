// C program for merge sort on singly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to split the singly linked list into two halves
struct Node* split(struct Node* head) {
    struct Node* fast = head;
    struct Node* slow = head;

    // Move fast pointer two steps and slow pointer
    // one step until fast reaches the end
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }

    // Split the list into two halves
    struct Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Function to merge two sorted singly linked lists
struct Node* merge(struct Node* first, struct Node* second) {
  
    // If either list is empty, return the other list
    if (first == NULL) return second;
    if (second == NULL) return first;

    // Pick the smaller value between first and second nodes
    if (first->data < second->data) {
        // Recursively merge the rest of the lists and
        // link the result to the current node
        first->next = merge(first->next, second);
        return first;
    }
    else {
        // Recursively merge the rest of the lists
        // and link the result to the current node
        second->next = merge(first, second->next);
        return second;
    }
}

// Function to perform merge sort on a singly linked list
struct Node* MergeSort(struct Node* head) {
  
    // Base case: if the list is empty or has only one node, 
    // it's already sorted
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Split the list into two halves
    struct Node* second = split(head);

    // Recursively sort each half
    head = MergeSort(head);
    second = MergeSort(second);

    // Merge the two sorted halves
    return merge(head, second);
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Function to create a new node
struct Node* createNode(int x) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create a hard-coded singly linked list:
    // 9 -> 8 -> 5 -> 2
    struct Node* head = createNode(9);
    head->next = createNode(8);
    head->next->next = createNode(5);
    head->next->next->next = createNode(2);

    head = MergeSort(head);
    printList(head);

    return 0;
}
