#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s)
{
    if ((s->top) == (s->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *s, int val)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
        printf("%d Pushed succesfull\n", val);
    }
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d pop succesfull\n", s->arr[s->top]);
        s->top--;
    }
}

void peek(struct stack *s,int pos){
    int index=pos-1;
    printf("the value at position %d is %d\n",pos,s->arr[index]); // from the top
}

void printStack(struct stack *s){
    for(int i=0;i<10;i++){
        printf("%d\n",s->arr[i]);
    }
}
void main(){
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 10;
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));
    push(st, 18);
    push(st, 61);
    push(st, 16);
    push(st, 51);
    push(st, 6);
    push(st, 5);
    push(st, 12);
    push(st, 16);
    push(st, 95);
    push(st, 56);
    push(st, 1256);

    // pop(st);
    // pop(st);
    // pop(st);

    // int pos = 6;
    // peek(st, pos);

    printStack(st);
}
