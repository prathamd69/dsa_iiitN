#include <stdio.h>
#define size 10

int front = -1, rear = -1;
int queue[size];

void enqueue(int value) {
    if (rear + 1 == size) {
        printf("\nQueue is Full!!");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty!!");
    } else {
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty!!!");
    } else {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d  ", queue[i]);
        }
    }
    printf("\n");
}

void unique() {
    int i = 0;
    int flag = 1;
    int count = 0;
    int temp = front;

    while (i <= rear - front) {
        count = 0;
        flag = 1;

        for (int j = front; j <= rear; j++) { 
            if (queue[temp] == queue[j]) {
                count++;
            }
            if (count == 2) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            printf("\nFirst Unique Element: %d\n", queue[temp]);
            return;
        }
        
        temp++;
        i++;
    }

    printf("\nNo Unique Element Found\n");
}

int main() {
    enqueue(10);
    enqueue(10);
    enqueue(9);
    enqueue(3);
    enqueue(3);
    enqueue(1);
    enqueue(1);
    enqueue(23);
    enqueue(17);

    display();
    
    unique();

    return 0;
}


/*
Queue elements are:
10  10  9  3  3  1  1  23  17  

First Unique Element: 9
*/