#include <stdio.h>
#define size 5

int front = -1, rear = -1;
int queue[size];

void enqueue(int value) {
    if (rear + 1 == front) {
        printf("\nqueue is Full!!");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) ;
        queue[rear] = value;
        printf("\nInserted -> %d", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("\nqueue is Empty!!");
    } else {
        printf("\nDeleted : %d", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1);
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nqueue is Empty!!!");
    } else {
        printf("\nqueue elements are:\n");
        int i = front;
        while (1) {
            printf("%d  ", queue[i]);
            if (i == rear) break;
            i = (i + 1);
        }
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(12);
    enqueue(9);
    enqueue(3);
    enqueue(3);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    dequeue();
    enqueue(23);
    dequeue();
    enqueue(17);
    display();

    return 0;
}

/*

Inserted -> 10
Inserted -> 12
Inserted -> 9
Inserted -> 3
Inserted -> 3
queue is Full!!
queue is Full!!
Deleted : 10
queue is Full!!
queue elements are:
12 9 3 

*/