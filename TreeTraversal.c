#include <stdio.h>
#include <stdlib.h>


struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree
struct Node * buildTree() {
    char data;
    printf("Enter data (enter '.' for no node): ");
    scanf(" %c", &data);

    if (data == '.') {
        return NULL;
    }

    struct Node* tree = createNode(data);

    printf("Enter left child of %c:\n", data);
    tree->left = buildTree();

    printf("Enter right child of %c:\n", data);
    tree->right = buildTree();

    return tree;
}

void preOrderTraversal(struct Node* tree) {
    if (tree == NULL) {
        return;
    }
    printf("%c ", tree->data);
    preOrderTraversal(tree->left);
    preOrderTraversal(tree->right);
}

void inOrderTraversal(struct Node* tree) {
    if (tree == NULL) {
        return;
    }
    inOrderTraversal(tree->left);
    printf("%c ", tree->data);
    inOrderTraversal(tree->right);
}

void postOrderTraversal(struct Node* tree) {
    if (tree == NULL) {
        return;
    }
    postOrderTraversal(tree->left);
    postOrderTraversal(tree->right);
    printf("%c ", tree->data);
}

int main() {
    int choice;
    printf("Enter the values to build the tree:\n");
    struct Node* tree = buildTree();

    do{
        printf("\n Tree Traversal Menu --\n");
        printf("1. For Pre Order.\n");
        printf("2. For In Order.\n");
        printf("3. For Post Order.\n");
        printf("4. For Exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nPre-order Traversal of the Tree:\n");
            preOrderTraversal(tree);
            break;
            case 2:printf("\nIn-order Traversal of the Tree:\n");
            inOrderTraversal(tree);
            break;
            case 3:printf("\nPost-order Traversal of the Tree:\n");
            postOrderTraversal(tree);
            break;
        }
    }
    while(choice!=4);
    return 0;
}