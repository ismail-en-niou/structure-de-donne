#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void prefixTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value); // Visit current node
        prefixTraversal(root->left); // Traverse left subtree
        prefixTraversal(root->right); // Traverse right subtree
    }
}

void postfixTraversal(Node* root) {
    if (root != NULL) {
        postfixTraversal(root->left); // Traverse left subtree
        postfixTraversal(root->right); // Traverse right subtree
        printf("%d ", root->value); // Visit current node
    }
}

void infixTraversal(Node* root) {
    if (root != NULL) {
        infixTraversal(root->left); // Traverse left subtree
        printf("%d ", root->value); // Visit current node
        infixTraversal(root->right); // Traverse right subtree
    }
}

int main() {
    // Creating a binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Prefix traversal: ");
    prefixTraversal(root);
    printf("\n");

    printf("Postfix traversal: ");
    postfixTraversal(root);
    printf("\n");

    printf("Infix traversal: ");
    infixTraversal(root);
    printf("\n");

    return 0;
}
