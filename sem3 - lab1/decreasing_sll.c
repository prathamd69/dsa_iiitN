// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int newdata){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

struct node* append(struct node* head, int newdata){
    
    struct node* newnode = createnode(newdata);
    
    if (head == NULL){
        return newnode;
    }
    
    struct node* temp = head;
    
    if (newdata > temp->data){
        newnode->next = temp;
        return newnode;
    }
    
    struct node* prev = NULL;

    while (temp->data >= newdata && temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp->data >= newdata && temp->next == NULL) {
        temp->next = newnode;
    } 
    
    else {
        prev->next = newnode;
        newnode->next = temp;
    }

    return head;
}

void printlist(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    
    int len, val;
    struct node* head = NULL;
    
    printf("Enter the num of values you want to insert - ");
    scanf("%d", &len);
    
    for(int i = 0; i < len; i++){
        printf("Enter the %dth value - ", i+1);
        scanf("%d",&val);
        head = append(head,val);
    }
    
    printf("\n\n The list is --  ");
    printlist(head);
    
    return 0;
}

/*
Enter the num of values you want to insert - 3
Enter the 1th value - 1
Enter the 2th value - 2
Enter the 3th value - 1


 The list is --  2 1 1 
*/