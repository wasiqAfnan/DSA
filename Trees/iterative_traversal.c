#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100]; // Assuming the maximum number of nodes in the tree is 100
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}


void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100]; // Assuming the maximum number of nodes in the tree is 100
    int top = -1;
    struct Node* current = root;
    struct Node* lastVisited = NULL;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        struct Node* peekNode = stack[top];
        
        if (peekNode->right != NULL && lastVisited != peekNode->right) {
            current = peekNode->right;
        } else {
            printf("%d ", peekNode->data);
            lastVisited = stack[top--];
        }
    }
}


void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100]; // Assuming the maximum number of nodes in the tree is 100
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            printf("%d ", current->data);
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        current = current->right;
    }
}

int main() {
    struct Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");


    return 0;
}
