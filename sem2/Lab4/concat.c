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
struct node* concatenate(struct node* head1, struct node* head2) {
    if (head1 == NULL) {
        return head2; 
    }

    struct node* temp = head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;}
int main() {
  
    int element;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    
    while(1){
        printf("Enter next element or -1 : ");
        scanf("%d", &element);
        
        if (element != -1){
            head1 = append(head1,element);
            continue;
        }
        else{
            break;
        }
    }

    while (1) {
        printf("Enter 2nd list next element: ");
        scanf("%d", &element);

        if (element == -1) {
            break;
        }

        head2 = append(head2, element);
    }
    
    printf("\nFirst Linked List: ");
    printList(head1);
    printf("\nSecond Linked List: ");
    printList(head2);
    
    head1 = concatenate(head1, head2);

    printf("\nConcatenated Linked List: ");
    printList(head1);


    return 0;
}