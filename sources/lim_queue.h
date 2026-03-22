#ifndef LIM_QUEUE_H_   /* Include guard */
#define LIM_QUEUE_H_
#include <stdbool.h>
#include <stdlib.h>

typedef void* Type;


typedef struct Node {
    struct Node* previous;
    struct Node* next;
    Type value;
} Node;

typedef struct Queue {
    Node* front;
    Node* back;
    int size;
} Queue;

// Create int linked Queue
Queue createQueue();

// Append in Queue
void pushInQueue(Queue* queue, Type value);

// Get at specific index with bounds checking
Type popFromQueue(Queue* queue);

// Get Queue first element
Type getQueueHead(Queue* queue);

// Check if queue is empty
bool isQueueEmpty(Queue* queue);

// Free heap allocated linked Queue if it is used
void freeQueue(Queue* queue);

#endif // LIM_QUEUE_H_
