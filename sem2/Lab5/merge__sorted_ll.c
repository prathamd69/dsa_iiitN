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

struct node* createnode(int element) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = NULL;
    return new_node;
}

struct node* append(struct node* head, int element) {

    struct node* new_node = createnode(element);

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


struct node *merger(struct node* head1, struct node* head2){
    
    // while (head1 != NULL || head2 != NULL){
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
        
    if (head1->data <= head2->data) {
        head1->next = merger(head1->next, head2);
        return head1;
    }
    else {
        head2->next = merger(head1, head2->next);
        return head2;
    }
    }
    
    


int main() {
  
    int element;
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("Enter elements for both lists in a sorted manner\n\n");
    
    while(1){
        printf("LL 1 -> Enter next element or -1 : ");
        scanf("%d", &element);
        
        if (element != -1){
            head2 = append(head2,element);
            continue;
        }
        else{
            break;
        }
    }
    
    printf("\n\nYour first Linked List is : ");
    printList(head2);
    printf("\n\n");
    
    while(1){
        printf("LL 2 -> Enter next element or -1 : ");
        scanf("%d", &element);
        
        if (element != -1){
            head1 = append(head1,element);
            continue;
        }
        else{
            break;
        }
    }
    printf("\n\nYour second Linked List is : ");
    printList(head1);
    
    printf("\n\nFinal List - ");
    struct node *final = merger(head1,head2);
    printList(final);



    return 0;
}