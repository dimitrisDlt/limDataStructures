#include <stdio.h>
#include <stdlib.h>
#include "lim_flow.h"


// Initialize new Flow structs.
struct Flow createFlow(int capacity) {

    struct Flow newVector;

    //If user wants bigger capacity than the predefine stack size
    //data is allocated directly in heap memory.
    if(capacity > DEFAULT_SIZE) {

        printf("Using heap data\n");

        //We set the capacity
        newVector.capacity = capacity;

        //We initialize internal heap array and set to zero to avoid existing junk values.
        newVector.newData = (Type*) calloc(capacity, sizeof(Type));

        //Binding between Flow content and heap memory buffer.
        newVector.data = newVector.newData;
    }
    else {

        printf("Using stack data\n");

        //Binding between Flow content and stack memory buffer.
        newVector.data = &newVector.stackData[0];
        newVector.newData = NULL;

        for (int i = 0; i < DEFAULT_SIZE; i++) {

            newVector.data[i] = 0;

        }

        newVector.capacity = DEFAULT_SIZE;
    }

    newVector.size = 0;

    printf("Created IntVector with size: %d\nCapacity: %d.\n", newVector.size, newVector.capacity);

    return newVector;
}

void appendInFlow(struct Flow* vector, int value) {

    if(vector->size >= vector->capacity) {

        vector->capacity *= 2;

        if(vector->newData == NULL) {

            vector->newData = (Type*) calloc(vector->capacity, sizeof(Type));

            for (int i = 0; i < DEFAULT_SIZE; i++) {

                vector->newData[i] = vector->stackData[i];
            }

            vector->data = vector->newData;
        }
        else {

            printf("Tora tha doume.\n");

            Type* newPtr = (Type*) calloc(vector->capacity, sizeof(Type));

            if(newPtr == NULL) {

                printf("Flow requested new space for increased buffer, but that failed.\n");
            }
            else {

                for(int k = 0; k < vector->size; k++) {
                    newPtr[k] = vector->data[k];
                    printf("Added %d\n", k);
                }

                //printf("Success in additions! Now freeing..\n");
                //free(vector->newData);
                free(vector->data);
                //printf("Freed, now reallocating.\n");

                vector->newData = newPtr;
                vector->data = vector->newData;
            }

        }

    }

    vector->data[vector->size] = value;
    vector->size++;

    //printf("New size is: %d\n", vector->size);

}

Type atFlowIndex(Flow* vector, int index) {

    if(index >= vector->size) {

        printf("Index is out of bounds! The function will return 0.\n");

        return 0;
    }

    return vector->data[index];
}

Type setFlowIndex(Flow* vector, int index, Type value) {

    if(index >= vector->size) {

        printf("Index is out of bounds! The function will return 0.\n");

        return 0;
    }

    vector->data[index] = value;

    return value;
}

Type getLastInFlow(Flow* vector) {

    return vector->data[vector->size - 1];
}

void freeFlow(struct Flow* vector) {


    if(vector->newData != NULL) {

        free(vector->newData);
    }

}
