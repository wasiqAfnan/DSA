#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    int num;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &num);

    if (num < 0)
    {
        return 0;
    }

    newNode->data = num;
    printf("Enter data for left child of %d\n", num);
    newNode->left = create();

    printf("Enter data for right child of %d\n", num);
    newNode->right = create();

    return newNode;
}

void preorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct node * search(struct node * root, int val)
{
    if (root == NULL)
    {
        printf("\nTree has no nodes OR Element is not present int tree\n");
        exit(0);
    }
    if (root->data < val)
    {
        return search(root->right, val);
    }
    else if (root->data > val)
    {
        return search(root->left, val);
    }
    else
    {
        printf("\n%d found", val);
    }

}

int isBST(struct node *root)
{
    if (root == NULL)
        return 1;

    if (root->left != NULL && root->left->data > root->data)
        return 0;

    if (root->right != NULL && root->right->data < root->data)
        return 0;

    return isBST(root->left) && isBST(root->right);
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void main()
{
    struct node * root = NULL;
    root=create();
    // inorderTraversal(root);
    // search(root, 5);

    if (isBST(root))
    {
        printf("\nThe binary tree is a BST.\n");
    }
    else
    {
        printf("\nThe binary tree is not a BST.\n");
    }

    printf("Inorder traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");

    int key = 10;
    root = deleteNode(root, key);

    printf("Inorder traversal after deletion of %d: ", key);
    inorderTraversal(root);
    printf("\n");
}