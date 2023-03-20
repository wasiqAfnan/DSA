#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

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

// void pop(node **top){
//     if(isEmpty(*top)){
//         printf("Stack underflow\n");
//     }
//     else{
//         node *p=*top;
//         *top=p->next;
//         printf("%d popped\n",p->data);
//         free(p);
//     }
// }
void peek(node *top,int pos){
    node *p=top;

    int i=0;
    while(i<pos-1 && p!=NULL){
        p=p->next;
        i++;
    }
    if(p!=NULL){
        printf("%d\n",p->data);
    }
    else{
        printf("Invalid position\n");
    }
}
void main(){
    node *top=NULL;
    top=push(top,78);
    top=push(top,68);
    top=push(top,98);
    top=push(top,8);
    top=push(top,58);

    // traversal(top);

    // pop(&top);
    // pop(&top);
    // pop(&top);
    // pop(&top);

    // traversal(top);

    peek(top,4);
}