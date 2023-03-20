#include <stdio.h>
#include <stdlib.h>
int maxsize = 5;

typedef struct queue
{
    int data;
    struct queue *next;
} quell;

quell *f = NULL;
quell *l = NULL;

void enqueue(int val)
{
    quell *n = (quell *)malloc(sizeof(quell));
    if (maxsize == 0)
    {
        printf("Overflow\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = l = n;
        }
        else
        {
            l->next = n;
            l = n;
        }
        printf("Enqueued %d\n", n->data);
        maxsize--;
    }
}

void dequeue()
{
    if(f==NULL){
        printf("Underflow\n");
    }
    else{
        quell *ptr = f;
        f=f->next;
        printf("%d dequeued\n",ptr->data);
        free(ptr);
    }
}
void traversal(quell *f)
{
    while (f != NULL)
    {
        printf("%d\n", f->data);
        f = f->next;
    }
}

void main()
{
    enqueue(98);
    enqueue(8);
    enqueue(6);
    enqueue(68);
    enqueue(25);
    enqueue(68);
    traversal(f);
    dequeue();
    dequeue();
    dequeue();
    traversal(f);
}