#ifndef Queue_H_
#define Queue_H_
#include <stdbool.h>

#define SIZE 258 // Define the size of the circular queue

typedef struct
{
    int x, y;
} QueueNode;

// Queue implementation
typedef struct
{
    QueueNode data[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int x, int y);
QueueNode dequeue(Queue *q);
QueueNode Front(Queue *q);

#endif