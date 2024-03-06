#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent the stack
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %c\n", item);
    } else {
        stack->items[++stack->top] = item;
    }
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return '\0'; // Return a null character in case of underflow
    } else {
        char item = stack->items[stack->top--];
        return item;
    }
}

// Function to display the elements in the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%c ", stack->items[i]);
        }
        printf("\n");
    }
}

