#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    printf("[");
    while (head != NULL) {
        printf("%d,", head->data);
        head = head->next;
    }
    printf("]");
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

    struct node* last = head;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return head;
}

void counter(struct node* head) {
    int count = 0;
    while (head != NULL) {
       
        count++;
        head = head->next;
    }
    printf("\nNumber of elements in your LL is %d", count);
}

int main() {
  
    int element;
    struct node *head = NULL;
    
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
    counter(head);


    return 0;
}
