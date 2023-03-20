#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct queue{
    int size;
    int f;
    int l;
    int *arr;
}queue;

int isFull(queue *ptr){
    if(ptr->l == ptr->size-1){
        return 1;
    }
    else{
        return  0;
    }
}

void enqueue(queue *ptr,int value){
    if (isFull(ptr)){
        printf("overflow\n");
    }
    else{
        ptr->l++;
        ptr->arr[ptr->l]=value;
        printf("Enqueued\n"); 
    }
}

int isEmpty(queue *ptr){
    if(ptr->l==ptr->f){
        return 1;
    }
    else{
        return 0;
    }
}

void dequeue(queue *ptr){
    if(isEmpty(ptr)){
        printf("Overflow\n");
    }
    else{
        ptr->f++;
        printf("%d is dequeued\n",ptr->arr[ptr->f]);
    }
}
void traversal(queue *ptr){
    int i=ptr->f+1;
    for(int i=ptr->f+1;i<=ptr->l;i++){
        printf("Element at %d is %d\n",i+1,ptr->arr[i]);
    }
}

void main(){
    queue rail;
    rail.size=20;
    rail.f=rail.l=-1;
    rail.arr=(int *)malloc(rail.size * sizeof(int));
    enqueue(&rail,58);
    enqueue(&rail,8);
    enqueue(&rail,5);
    enqueue(&rail,68);
    traversal(&rail);
    dequeue(&rail);
    dequeue(&rail);
    traversal(&rail);
}