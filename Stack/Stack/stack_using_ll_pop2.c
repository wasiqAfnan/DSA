#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *top=NULL; //make top a global variable so do not have to dereference in pop func

void traversal(node *top){
    node *p=top;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

int isFull(node *top){
    node *p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

node* push(node *top,int value){
    if(isFull(top)){
        printf("Failed to push\n");
    }
    else{
        node *p=(struct node *)malloc(sizeof(struct node));
        p->data=value;
        p->next=top;
        top=p;
        printf("%d pushed succesful\n",p->data);
        return top;
    }
}

int isEmpty(node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void pop(node *ftop){
    if(isEmpty(ftop)){
        printf("Stack underflow\n");
    }
    else{
        node *p=ftop;
        top=p->next;
        printf("%d popped\n",p->data);
        free(p);
    }
}

void main(){
    top=push(top,78);
    top=push(top,68);
    top=push(top,98);
    top=push(top,8);
    top=push(top,58);

    traversal(top);

    pop(top);
    pop(top);
    pop(top);
    pop(top);

    traversal(top);
}