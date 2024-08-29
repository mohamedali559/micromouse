#include "Queue.h"

void initQueue(Queue *q)
{
    q->front = q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int x, int y)
{
    if (q->rear == SIZE - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
}

QueueNode dequeue(Queue *q)
{
    QueueNode temp = q->data[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return temp;
}

QueueNode Front(Queue *q)
{

    QueueNode temp = q->data[q->front];
    return temp;
}
