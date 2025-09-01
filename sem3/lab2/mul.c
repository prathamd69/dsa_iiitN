#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *link;
};

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

struct node *mul(struct node *head3, struct node *head1, struct node *head2)
{

    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *temp3 = head3;
    float new_data = 0;
    int new_expo = 0;

   while (temp1){
       temp2 = head2;
       
       while(temp2){
            new_data = temp1->coeff*temp2->coeff;
            new_expo = temp1->expo + temp2->expo;
            head3 = polynomial(head3,new_data,new_expo);
            temp2 = temp2->link;
       }
       temp1 = temp1->link;
   }

    return head3;
}

int main()
{
    int coefficient, exponent, len;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    printf("---- Polynomial 1 ----\n");
    printf("Enter the num of terms you want to insert - ");
    scanf("%d", &len);
    printf("\n");

    for (int i = 0; i < len; i++)
    {
        printf("Enter the coeff - ");
        scanf("%d", &coefficient);
        printf("Enter the expo - ");
        scanf("%d", &exponent);
        head1 = polynomial(head1, coefficient, exponent);
    }

    printf("\n Polynomial 1 -->  ");
    display(head1);

    printf("\n\n---- Polynomial 2 ----\n");
    printf("Enter the num of terms you want to insert - ");
    scanf("%d", &len);
    printf("\n");

    for (int i = 0; i < len; i++)
    {
        printf("Enter the coeff - ");
        scanf("%d", &coefficient);
        printf("Enter the expo - ");
        scanf("%d", &exponent);
        head2 = polynomial(head2, coefficient, exponent);
    }

    printf("\n Polynomial 2 -->  ");
    display(head2);

    head3 = mul(head3, head1, head2);
    printf("\n\n product of both Polynomials -> ");
    display(head3);

    return 0;
}
/*
---- Polynomial 1 ----
Enter the num of terms you want to insert - 2

Enter the coeff - 3
Enter the expo - 1
Enter the coeff - 2
Enter the expo - 0

 Polynomial 1 -->  3.00X(1) +2.00

---- Polynomial 2 ----
Enter the num of terms you want to insert - 3

Enter the coeff - 4
Enter the expo - 2
Enter the coeff - 2
Enter the expo - 1
Enter the coeff - 9
Enter the expo - 0

 Polynomial 2 -->  4.00X(2) +2.00X(1) +9.00

 product of both Polynomials -> 12.00X(3) +14.00X(2) +31.00X(1) +18.00
*/