#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size;
    int f;
    int l;
    int *arr;
}queue;

int isFull(queue *ptr){
    if((ptr->l+1)%ptr->size == ptr->f){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(queue *ptr,int value){
    if(isFull(ptr)){
        printf("Overflow\n");
    }
    else{
        ptr->l=(ptr->l+1)%ptr->size;
        ptr->arr[ptr->l]=value;
        printf("Enqueued\n");
    }
}

int isEmpty(queue *ptr){
    if(ptr->f==ptr->l){
        return 1;
    }
    else{
        return 0;
    }
}

void dequeue(queue *ptr){
    if(isEmpty(ptr)){
        printf("Underflow\n");
    }
    else{
        ptr->f=(ptr->f+1)%ptr->size;
        printf("Dequeued %d\n",ptr->arr[ptr->f]);
    }
}

void traversal(queue *ptr){
    for(int i=(ptr->f)+1;i<=ptr->l;i++){
        printf("element at %d is %d\n",i,ptr->arr[i]);
    }
}

void main(){
    queue rail;
    rail.size=5;
    rail.f=rail.l=0;
    rail.arr=(int *)malloc(rail.size * sizeof(int));
    enqueue(&rail,58);
    enqueue(&rail,8);
    enqueue(&rail,5);
    traversal(&rail);
    dequeue(&rail);
    dequeue(&rail);
    traversal(&rail);
}
