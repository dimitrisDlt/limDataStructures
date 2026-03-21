#include "lim_stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack createStack() {

	Stack newStack;
	newStack.size = 0;
	newStack.head = NULL;

	return newStack;
}

void pushInStack(Stack* stack, Type value) {

	if(stack->head == NULL) {

		stack->head = malloc(sizeof(Node));
		stack->head->value = value;
		stack->head->next = NULL;
	}
	else {

		Node* newNode = malloc(sizeof(Node));
		newNode->value = value;
		newNode->next = stack->head;
		stack->head = newNode;
	}

	stack->size++;
}

Type popFromStack(Stack* stack) {

	if(stack->head == NULL) {

		printf("Stack is empty! Function will return 0.\n");

		return 0;
	}

	Type poppedValue = stack->head->value;

	if(stack->size > 1) {

		Node* newHead = stack->head->next;

		free(stack->head);

		stack->head = newHead;
	}
	else {

		free(stack->head);
		stack->head = NULL;
	}

	stack->size--;

	return poppedValue;
}

Type getStackHead(Stack* stack) {

	if(stack->head == NULL) {

		printf("Stack is empty! Function will return 0.\n");

		return 0;
	}

	return stack->head->value;
}

bool isStackEmpty(Stack* stack) {

	return stack->size > 0;
}

void freeStack(Stack* stack) {

	while (stack->size > 0) {

		popFromStack(stack);
	}
}
