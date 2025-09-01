#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *link;
};

// struct node* Node;

struct node *createnode(float coefficient, int exponent)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coefficient;
    newnode->expo = exponent;
    newnode->link = NULL;

    return newnode;
}

struct node *polynomial(struct node *head, float coefficient, int exponent)
{

    struct node *newnode = createnode(coefficient, exponent);

    if (head == NULL)
    {
        return newnode;
    }

    struct node *temp = head;

    if (exponent > temp->expo)
    {
        newnode->link = temp;
        return newnode;
    }

    struct node *prev = NULL;

    while (temp->expo > exponent && temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    if (temp != NULL && temp->expo == exponent)
    {
        temp->coeff += coefficient;
        free(newnode);
        return head;
    }

    if (temp->expo > exponent && temp->link == NULL)
    {
        temp->link = newnode;
    }

    else
    {
        prev->link = newnode;
        newnode->link = temp;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    printf("%.2fX(%d) ", temp->coeff, temp->expo);
    temp = temp->link;

    while (temp != NULL)
    {

        if (temp->coeff > 0)
        {
            if (temp->expo > 0)
            {
                printf("+%.2fX(%d) ", temp->coeff, temp->expo);
                temp = temp->link;
            }

            else
            {
                printf("+%.2f", temp->coeff);
                temp = temp->link;
            }
        }

        else
        {
            if (temp->expo > 0)
            {
                printf("%.2fX(%d) ", temp->coeff, temp->expo);
                temp = temp->link;
            }

            else
            {
                printf("%.2f", temp->coeff);
                temp = temp->link;
            }
        }
    }
}

int main()
{
    int coefficient, exponent, len;
    struct node *head = NULL;

    printf("Enter the num of terms you want to insert - ");
    scanf("%d", &len);
    printf("\n");

    for (int i = 0; i < len; i++)
    {
        printf("Enter the coeff - ");
        scanf("%d", &coefficient);
        printf("Enter the expo - ");
        scanf("%d", &exponent);
        head = polynomial(head, coefficient, exponent);
    }

    printf("\n\n Polynomial -->  ");
    display(head);

    return 0;
}


/*
Enter the num of terms you want to insert - 5

Enter the coeff - 30
Enter the expo - 5
Enter the coeff - -10
Enter the expo - 4
Enter the coeff - 5
Enter the expo - 2
Enter the coeff - -3
Enter the expo - 2
Enter the coeff - 8
Enter the expo - 1


 Polynomial -->  30.00X(5) -10.00X(4) +2.00X(2) +8.00X(1)
*/

/*
Enter the num of terms you want to insert - 3

Enter the coeff - 10
Enter the expo - 3
Enter the coeff - 3
Enter the expo - 2
Enter the coeff - -19
Enter the expo - 0


 Polynomial -->  10.00X(3) +3.00X(2) -19.00
*/

/*
Enter the num of terms you want to insert - 2

Enter the coeff - 1
Enter the expo - 0
Enter the coeff - 1
Enter the expo - 10


 Polynomial -->  1.00X(10) +1.00
 */