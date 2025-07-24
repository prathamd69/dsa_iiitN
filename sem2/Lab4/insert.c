#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


void printList(struct node* head) {
    // printf("[");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    // printf("]");
}

struct node* createnode(int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

struct node* append(struct node* head, int new_data) {

    struct node* new_node = createnode(new_data);

    if (head == NULL) {
        return new_node;
    }

    struct node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return head;
}
struct node* index_append(struct node* head, int pos, int new_data) {
    struct node* new_node = createnode(new_data);

    if (pos == 0) {
        new_node->next = head;
        return new_node;
    }

    struct node* temp = head;
    int current_pos = 0;

   
    while (temp != NULL && current_pos < pos - 1) {
        temp = temp->next;
        current_pos++;
    }

    
    if (temp == NULL) {
        printf("Position not possible.\n");
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}
int main() {
  
    int element;
    struct node *head = NULL;
    int pos,new_data;
    
    while(1){
        printf("Enter next element or -1 : ");
        scanf("%d", &element);
        
        if (element != -1){
            head = append(head,element);
            continue;
        }
        else{
            break;
        }
    }
    printf("\n\nYour enterted Linked List is : ");
    printList(head);
    
    printf("\n\nEnter position to insert a new number: ");
    scanf("%d", &pos);
    printf("Enter the new number: ");
    scanf("%d", &new_data);

    head = index_append(head, pos, new_data);

    printf("\nLinked list after insertion: ");
    printList(head);

    return 0;
}