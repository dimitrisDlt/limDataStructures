#ifndef LIM_LIST_H_   /* Include guard */
#define LIM_LIST_H_

#include <stdbool.h>

typedef void* Type;

typedef struct Node {
    struct Node* previous;
    struct Node* next;
    Type value;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    int size;
} List;

// Create int linked list
struct List createList();

// Append in List
bool appendInList(struct List* list, Type value);

bool insertInList(List* list, int index, Type value);

// Get at specific index with bounds checking
Type atListIndex(List* list, int index);

// Get list first element
Type getListHead(List* list);

// Get list last element
Type getListTail(List* list);

// Set value at specific index with bounds checking
Type setListIndex(List* vector, int index, Type value);

// Free heap allocated linked list if it is used
void freeList(List* list);

#endif // LIM_LIST_H_
