#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode *node) {
    if (!node) return 0;
    return max(height(node->left), height(node->right)) + 1;
}

struct TreeNode* rotateRight(struct TreeNode *pivot) {
    struct TreeNode *child = pivot->left;
    if (!child) return pivot;

    struct TreeNode *temp = child->right;
    child->right = pivot;
    pivot->left = temp;

    printf("Right Rotation on node: %d\n", pivot->val);
    return child;
}

struct TreeNode* rotateLeft(struct TreeNode *pivot) {
    struct TreeNode *child = pivot->right;
    if (!child) return pivot;

    struct TreeNode *temp = child->left;
    child->left = pivot;
    pivot->right = temp;

    printf("Left Rotation on node: %d\n", pivot->val);
    return child;
}

struct TreeNode* balance(struct TreeNode *node) {
    int lh = height(node->left);
    int rh = height(node->right);

    if (lh - rh > 1) {
        if (height(node->left->left) >= height(node->left->right)) {
            return rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (rh - lh > 1) {
        if (height(node->right->right) >= height(node->right->left)) {
            return rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

struct TreeNode* insert(struct TreeNode *node, int key) {
    if (!node) {
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newNode->val = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < node->val)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return balance(node);
}

void inorder(struct TreeNode *node) {
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->val);
    inorder(node->right);
}

int main() {
    struct TreeNode *root = NULL;
    int values[] = {50, 40, 30, 20, 10, 5};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Inorder traversal of AVL tree: ");
    inorder(root);
    printf("\n");

    return 0;
}