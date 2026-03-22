#include "lim_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue createQueue() {

    Queue newQueue;
    newQueue.size = 0;
    newQueue.front = NULL;
    newQueue.back = NULL;

    return newQueue;
}

void pushInQueue(Queue* queue, Type value) {

    if(queue->front == NULL) {

        queue->front = (Node*) malloc(sizeof(Node));
        queue->front->value = value;
        queue->front->previous = NULL;
        queue->front->next = NULL;
        queue->back = queue->front;
    }
    else {

        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->value = value;
        newNode->previous = queue->back;
        queue->back->next = newNode;
        queue->back = newNode;
    }

    queue->size++;
}

Type popFromQueue(Queue* queue) {

    if(queue->front == NULL) {

        printf("Queue is empty! Function will return 0.\n");

        return 0;
    }

    Type poppedValue = queue->front->value;

    if(queue->size > 1) {

        Node* newFront = queue->front->next;
        newFront->previous = NULL;

        free(queue->front);

        queue->front = newFront;
    }
    else {

        free(queue->front);
        queue->front = NULL;
        queue->back = NULL;
    }

    queue->size--;

    return poppedValue;
}

Type getQueueHead(Queue* queue) {

    if(queue->front == NULL) {

        printf("Queue is empty! Function will return 0.\n");

        return 0;
    }

    return queue->front->value;
}

bool isQueueEmpty(Queue* queue) {

    return queue->size > 0;
}

void freeQueue(Queue* queue) {

    while (queue->size > 0) {

        popFromQueue(queue);
    }
}
