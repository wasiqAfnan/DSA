#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node *next;
};

void traverse(struct node *ptr){
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct node * deleteAtFirst(struct node *ptr){
    struct node * q = ptr;
    ptr = ptr->next;

    free(q);
    return ptr;
}

struct node * deleteAtLast(struct node *ptr){
    struct node *p = ptr;
    struct node *q = ptr->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return ptr;
}

struct node * deleteAtPos(struct node *ptr,int pos){
    struct node *p = ptr;
    struct node *q = ptr->next;
    int i = 0;
    while(i < pos-2){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return ptr;
}
void main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));
    struct node *sixth = (struct node *)malloc(sizeof(struct node));
    struct node *seventh = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = sixth;

    sixth->data = 60;
    sixth->next = seventh;

    seventh->data = 70;
    seventh->next = NULL;
    
    traverse(head);
    // Deleting first node
    printf("\nAfter deleting First node\n");
    head = deleteAtFirst(head);
    traverse(head);

    // Deleting first node
    printf("\nAfter deleting Last node\n");
    head = deleteAtLast(head);
    traverse(head);

    // Deleting at position
    printf("\nAfter deleting at position\n");
    head = deleteAtPos(head,4);
    traverse(head);
}