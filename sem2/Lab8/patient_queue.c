#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int age;
    char name[20];
    int num;
    struct node *next;
} patient;

patient *front = NULL, *rear = NULL;
int counter = 0;

void enqueue(char name[], int age) {
    patient *new = (patient *)malloc(sizeof(patient));
    if (!new) {
        printf("\nMemory allocation failed\n");
        return;
    }

    new->age = age;
    new->num = ++counter;
    strcpy(new->name, name);
    new->next = NULL;

    if (!front) {
        front = rear = new;
    } else {
        rear->next = new;
        rear = new;
    }
}

void dequeue() {
    if (!front) {
        printf("\nQueue is empty!\n");
        return;
    }

    patient *del = front;
    front = front->next;
    free(del);

    if (!front) {
        rear = NULL;
    } else {
        patient *t = front;
        while (t) {
            t->num--;
            t = t->next;
        }
        counter--;
    }
}

void display() {
    if (!front) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\nName,Age,patient_num\n");
    patient *t = front;
    while (t) {
        printf("%s,%d,%d\n", t->name, t->age, t->num);
        t = t->next;
    }
}

int main() {
    enqueue("Pratham", 20);
    enqueue("Aryan", 18);
    enqueue("Dhruv", 18);
    enqueue("Aditya", 20);
    enqueue("Anant", 19);
    
    display();
    printf("\n");

    dequeue();
    dequeue();

    enqueue("gaykar", 19);
    dequeue();
    dequeue();

    enqueue("Bhati", 20);
    display();
    printf("\n");

    return 0;
}