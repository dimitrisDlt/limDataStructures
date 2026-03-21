#ifndef LIM_STACK_H_   /* Include guard */
#define LIM_STACK_H_
#include <stdbool.h>
#include <stdlib.h>

typedef int Type;


typedef struct Node {
    struct Node* next;
    Type value;
} Node;

typedef struct Stack {
    Node* head;
    int size;
} Stack;

// Create int linked Stack
Stack createStack();

// Append in Stack
void pushInStack(Stack* stack, Type value);

// Get at specific index with bounds checking
Type popFromStack(Stack* stack);

// Get Stack first element
Type getStackHead(Stack* stack);

// Check if stack is empty
bool isStackEmpty(Stack* stack);

// Free heap allocated linked Stack if it is used
void freeStack(Stack* stack);

#endif // LIM_STACK_H_
