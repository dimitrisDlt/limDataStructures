#include "lim_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct List createList() {

    List newList;

    newList.head = NULL;
    newList.tail = NULL;
    newList.size = 0;

    return newList;
}

bool appendInList(struct List* list, Type value) {

    if(list->head == NULL) {

        printf("Creating list head..\n");

        list->head = malloc(sizeof(Node));

        if(list->head == NULL) {

            printf("Failed to malloc list head. Function will return false.\n");
            return false;
        }

        list->head->value = value;
        list->head->next = NULL;
        list->size = 1;
        list->tail = list->head;

        return true;
    }
    else {

        if(list->head == list->tail) {

            printf("Creating list second element..\n");

            list->head->next = malloc(sizeof(Node));

            if(list->head->next == NULL) {

                printf("Failed to malloc list second element. Function will return false.\n");
                return false;
            }

            list->head->next->value = value;
            list->head->next->previous = list->head;
            list->head->next->next = NULL;
            list->size++;
            list->tail = list->head->next;

            return true;
        }
        else {

            printf("Creating new list element..\n");

            Node* currentNode = list->head->next;

            while(currentNode->next) {

                currentNode = currentNode->next;
            }

            currentNode->next = malloc(sizeof(Node));

            if(currentNode->next == NULL) {

                printf("Failed to malloc list new element. Function will return false.\n");
                return false;
            }

            currentNode->next->value = value;
            currentNode->next->previous = currentNode;
            currentNode->next->next = NULL;
            list->tail = currentNode->next;
            list->size++;

            return true;
        }
    }
}

bool insertInList(List* list, int index, Type value) {

    if(index > list->size) {

        printf("Index requested for insertion exceeds list size! Function will return false.\n");
        return false;
    }

    if(index == list->size) {
        appendInList(list, value);
        return true;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL) {

        printf("Insertion failed due to corrupt malloc() command! Function will exit without insertion.\n");
        return false;
    }

    newNode->value = value;

    int isIndexNearEnd = (int) (index > list->size / 2);

    switch (isIndexNearEnd) {

        case false: {

            Node* currentNode = list->head;

            int count = 0;

            while(currentNode->next && count < index) {

                currentNode = currentNode->next;
                count++;
            }

            newNode->previous = currentNode->previous;
            currentNode->previous->next = newNode;

            newNode->next = currentNode;
            currentNode->previous = newNode;

            list->size++;

            return true;

        }

        case true: default: {

            Node* currentNode = list->tail;

            int count = list->size - 1;

            while(currentNode->previous && count > index) {

                currentNode = currentNode->previous;
                count--;
            }

            newNode->previous = currentNode->previous;
            currentNode->previous->next = newNode;

            newNode->next = currentNode;
            currentNode->previous = newNode;

            list->size++;

            return true;
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

    Node* currentNode = list->head;

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

    Node* currentNode = list->head;

    while(currentNode->next) {

        currentNode = currentNode->next;

        if(currentNode->previous != NULL) {

            free(currentNode->previous);
        }
    }
}
