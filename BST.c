#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Search Tree
struct Node {
    int value;
    struct Node *left, *right;
};

// Creating a new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Inserting node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);

    return root;
}

// Binary Search in BST
struct Node* binarySearch(struct Node* root, int target) {
    if (root == NULL || root->value == target)
        return root;
    if (target < root->value)
        return binarySearch(root->left, target);
    return binarySearch(root->right, target);
}

// In-order traversal to print the tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}
