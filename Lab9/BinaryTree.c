/*
 
 1. Write a program to construct a binary tree and implement the following - 
 -> Inorder, Preorder, Postorder
 
 2. Implement function to - 
 -> count the total num. of nodes
 -> count the num. of leaf nodes
 -> find the height of binary tree
 
 3. Implement Binary search tree and following alongside - 
 -> Insertion
 -> Deletion
 -> Search
 -> Inorder transeversal to display sorted elements
 
 4. Given inorder and preorder (or postorder) transversal, reconstruct the binary tree.
 
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left, *right;
};

struct node* createNode(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct node* make_node() {
    int val;
    printf("Enter value (-1 to stop): ");
    scanf("%d", &val);

    if (val == -1) return NULL;

    struct node* new_node = createNode(val);
    printf("Enter left child of %d - ", val);
    new_node->left = make_node();
    printf("Enter right child of %d - ", val);
    new_node->right = make_node();
    
    return new_node;
}

void inorder(struct node* root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if (root == NULL) return;
    printf("%d, ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d, ", root->data);
}


int main(){
    struct node* root = NULL;
    root = make_node();
    
    printf("\n\nInorder - ");
    inorder(root);
    
    printf("\nPreorder - ");
    preorder(root);
    
    printf("\nPostorder - ");
    postorder(root);
}

/*

Output - 

Enter value (-1 to stop): 10
Enter left child of 10 - Enter value (-1 to stop): 8
Enter left child of 8 - Enter value (-1 to stop): 7
Enter left child of 7 - Enter value (-1 to stop): -1
Enter right child of 7 - Enter value (-1 to stop): -1
Enter right child of 8 - Enter value (-1 to stop): 9
Enter left child of 9 - Enter value (-1 to stop): -1
Enter right child of 9 - Enter value (-1 to stop): -1
Enter right child of 10 - Enter value (-1 to stop): 12
Enter left child of 12 - Enter value (-1 to stop): 11
Enter left child of 11 - Enter value (-1 to stop): -1
Enter right child of 11 - Enter value (-1 to stop): -1
Enter right child of 12 - Enter value (-1 to stop): 13
Enter left child of 13 - Enter value (-1 to stop): -1
Enter right child of 13 - Enter value (-1 to stop): -1


Inorder - 7, 8, 9, 10, 11, 12, 13, 
Preorder - 10, 8, 7, 9, 12, 11, 13, 
Postorder - 7, 9, 8, 11, 13, 12, 10, 

*/