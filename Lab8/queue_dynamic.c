#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node *front, *rear;
};

struct queue* createqueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue* q, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    
    printf("\nInserted -> %d", value);
}

void dequeue(struct queue* q) {
    if (q->front == NULL) {
        printf("\nqueue is Empty!!");
        return;
    }

    struct node* temp = q->front;
    printf("\nDeleted : %d", temp->data);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

void display(struct queue* q) {
    if (q->front == NULL) {
        printf("\nqueue is Empty!!");
        return;
    }

    printf("\nqueue elements are:\n");
    struct node* temp = q->front;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue* q = createqueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    dequeue(q);
    display(q);

    return 0;
}

/*
Inserted -> 10
Inserted -> 20
Inserted -> 30
Inserted -> 40
Inserted -> 50
Deleted : 10
Queue elements are:
20  30  40  50  
*/