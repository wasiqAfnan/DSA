#include <stdio.h>
#include <stdlib.h>

// tree looks like
/*       4
        /\
       1  6
      /\ 
     5  2
*/
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void preorderTraversal(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void inorderTraversal(struct node *root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
}

void main()
{
    struct node *n1 = createNode(4);
    struct node *n2 = createNode(1);
    struct node *n3 = createNode(6);
    struct node *n4 = createNode(5);
    struct node *n5 = createNode(2);

    // linking the nodes

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    // Preorder traversal
    printf("Preorder Traversal\n");
    preorderTraversal(n1);
    printf("\n");

    // Postorder traversal
    printf("Postorder Traversal\n");
    postorderTraversal(n1);
    printf("\n");

    // inorder traversal
    printf("Inorder Traversal\n");
    inorderTraversal(n1);
    printf("\n");
}