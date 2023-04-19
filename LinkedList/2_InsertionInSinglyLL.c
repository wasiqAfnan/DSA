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

struct node * insertFirst(struct node *ptr,int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = ptr;
    return new;
}

struct node * insertIndex(struct node *ptr,int pos,int data){
    struct node *temp = ptr;
    int i = 0;
    while(i < pos - 2){
        temp = temp->next;
        i++;
    }

    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = temp->next;
    temp->next = new;
    return ptr;
}


struct node * insertLast(struct node *ptr,int data){
    struct node *temp = ptr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    temp->next = new;
    new->data = data;
    new->next = NULL;
    return ptr;
}

void main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    // traverse(head);
    head = insertFirst(head,50);
    head = insertLast(head,100);
    head = insertIndex(head,3,200);
    traverse(head);
}