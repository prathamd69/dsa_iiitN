struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;  
    struct Node* curr = head; 
    struct Node* next = NULL; 
  
    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;        
    }

    return prev; 
}


struct node* separate_even_indices(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL; // Edge case: no even-indexed nodes exist
    }

    struct node* temp1 = head;          // Pointer for odd-indexed nodes
    struct node* temp2 = head->next;    // Pointer for even-indexed nodes
    struct node* head2 = head->next;    // Head of even-indexed nodes list

    while (temp1 != NULL && temp2 != NULL) {
        // Update next pointer of odd-indexed node
        if (temp1->next != NULL) {
            temp1->next = temp1->next->next;
        }

        // Update next pointer of even-indexed node
        if (temp2->next != NULL) {
            temp2->next = temp2->next->next;
        }

        temp1 = temp1->next; // Move odd pointer forward
        temp2 = temp2->next; // Move even pointer forward
    }

    return head2; // Return the head of the even-indexed nodes list
}
