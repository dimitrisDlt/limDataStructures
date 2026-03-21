#include "lim_list.h"
#include <stdio.h>
#include <stdlib.h>

struct List createList() {

    List newList;

    newList.head = NULL;
    newList.tail = NULL;
    newList.size = 0;

    return newList;
}

void appendList(struct List* list, Type value) {

    if(list->head == NULL) {

        printf("Creating list head..\n");

        list->head = malloc(sizeof(IntNode));
        list->head->value = value;
        list->head->next = NULL;
        list->size = 1;
        list->tail = list->head;
    }
    else {

        if(list->head == list->tail) {

            printf("Creating list second element..\n");

            list->head->next = malloc(sizeof(IntNode));
            list->head->next->value = value;
            list->head->next->previous = list->head;
            list->head->next->next = NULL;
            list->size++;
            list->tail = list->head->next;
        }
        else {

            printf("Creating new list element..\n");

            IntNode* currentNode = list->head->next;

            while(currentNode->next) {

                currentNode = currentNode->next;
            }

            currentNode->next = malloc(sizeof(IntNode));
            currentNode->next->value = value;
            currentNode->next->previous = currentNode;
            currentNode->next->next = NULL;
            list->tail = currentNode->next;
            list->size++;
        }
    }
}

Type atListIndex(List* list, int index) {

    // TODO: Implement scenario for starting from the end.
    //int middle = list->size / 2;

    if(index >= list->size) {

        printf("Index is out of bounds! Function will return 0.\n");

        return 0;
    }

    IntNode* currentNode = list->head;

    if(list->head == NULL) {

        printf("List is empty! Function will return 0.\n");

        return 0;
    }

    for(int i = 0; i < index; i++) {

        currentNode = currentNode->next;
    }

    return currentNode->value;
}

Type getListHead(List* list) {

    if(list->head == NULL) {
        printf("List is empty! Function will return 0.\n");

        return 0;
    }

    return list->head->value;
}

Type getListTail(List* list) {

    if(list->tail == NULL) {
        printf("List is empty! Function will return 0.\n");

        return 0;
    }

    return list->tail->value;
}

void freeList(List* list) {

    if(list->head == NULL) {

        printf("List is empty! Function does not have to release memory.\n");

        return;
    }

    IntNode* currentNode = list->head;

    while(currentNode->next) {

        currentNode = currentNode->next;

        if(currentNode->previous != NULL) {

            free(currentNode->previous);
        }
    }
}
