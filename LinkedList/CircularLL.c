#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void traversal(struct node *head){
    struct node *p=head;
    do{
        printf("%d\n",p->data);
        p=p->next;
    }while(p!=head);
}
void main(){
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third=(struct node *)malloc(sizeof(struct node));
    struct node *fourth=(struct node *)malloc(sizeof(struct node));

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=head;

    head->data=20;
    second->data=15;
    third->data=10;
    fourth->data=5;

    traversal(head);
}
