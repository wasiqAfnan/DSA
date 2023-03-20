#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * twoWayTraversal(struct node *head){
    struct node *p=head;
    while(p->next!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
    
    printf("Backward printing\n");
    
    do{
        printf("%d\n",p->data);
        p=p->prev;
    }while(p!=NULL);
}
void main(){
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third=(struct node *)malloc(sizeof(struct node));
    struct node *fourth=(struct node *)malloc(sizeof(struct node));

    head->next=second;
    head->prev=NULL;

    second->next=third;
    second->prev=head;

    third->next=fourth;
    third->prev=second;

    fourth->next=NULL;
    fourth->prev=third;

    head->data=20;
    second->data=15;
    third->data=10;
    fourth->data=5;

    head=twoWayTraversal(head);
}