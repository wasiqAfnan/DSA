#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int f = -1, r = -1;

void enqueueFront(int val)
{
    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Queue is full on front side\n");
    }

    else if (f == -1 && r == -1)
    {
        f = r = 0;
        queue[f] = val;
        printf("Enqueued Successful\n");
    }

    else if (f == 0)
    {
        f = N - 1;
        queue[f] = val;
        printf("Enqueued Successful\n");
    }

    else
    {
        f--;
        queue[f] = val;
        printf("Enqueued Successful\n");
    }
}

void enqueueRear(int val)
{
    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("queue is full on rear side\n");
    }

    else if (f == -1 && r == -1)
    {
        f = r = 0;
        queue[r] = val;
        printf("Enqueued Successful\n");
    }

    else if (r == N - 1)
    {
        r = 0;
        queue[r] = val;
        printf("Enqueued Successful\n");
    }

    else
    {
        r++;
        queue[r] = val;
        printf("Enqueued Successful\n");
    }
}

void display()
{
    int i = f;
    while (i != r)
    {
        printf("%d\n", queue[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", queue[r]);
}

void dequeueFront()
{
    if (f == -1 && r == -1)
    {
        printf("underflow\n");
    }

    else if (f == r)
    {
        printf("%d\n", queue[f]);
        f = r = -1;
    }

    else if (f == N - 1)
    {
        printf("%d\n", queue[f]);

        f = 0;
    }

    else
    {
        printf("%d\n", queue[f]);
        f++;
    }
}

void dequeueRear()
{
    if (f == -1 && r == -1)
    {
        printf("underflow");
    }

    else if (f == r)
    {
        printf("%d\n", queue[r]);
        f = r = -1;
    }

    else if (r == 0)
    {
        printf("%d\n", queue[r]);
        r = N - 1;
    }

    else
    {
        printf("%d\n", queue[r]);
        r--;
    }
}

void main()
{
    enqueueFront(20);
    enqueueFront(50);
    enqueueRear(-11);
    enqueueFront(69);
    enqueueFront(64);
    enqueueRear(98);
    display();
    printf("Dequeue\n");

    dequeueFront();
    dequeueRear();
    dequeueFront();
    printf("End of Main");
}
