#ifndef LIM_FLOW_H_   /* Include guard */
#define LIM_FLOW_H_

#include <stddef.h>

#define DEFAULT_SIZE 100

typedef int Type;

typedef struct Flow {
    Type* data;
    Type stackData[DEFAULT_SIZE];
    Type* newData;
    size_t size;
    size_t capacity;
} Flow;

// Create int
struct Flow createFlow(int capacity);

// Append in Flow
void appendInFlow(Flow* vector, Type value);

// Get at specific index with bounds checking
Type atFlowIndex(Flow* vector, int index);

// Set value at specific index with bounds checking
Type setFlowIndex(Flow* vector, int index, Type value);

// Get last item
Type getLastInFlow(Flow* vector);

// Free heap allocated array if it is used
void freeFlow(struct Flow* vector);

#endif // LIM_FLOW_H_
