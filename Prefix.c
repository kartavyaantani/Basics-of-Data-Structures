#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Structure to define the stack
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Function to create a new stack
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == stack->capacity - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow. Cannot push %d.\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow. Cannot pop from an empty stack.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to evaluate a prefix expression
int evaluatePrefix(char *expression) {
    struct Stack *stack = createStack(100); // Assuming a maximum expression length of 100
    int operand1, operand2, result;
    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0'); // Convert char to int
        } else if (expression[i] == ' ' || expression[i] == '\t') {
            // Skip whitespace
            continue;
        } else {
            operand1 = pop(stack);
            operand2 = pop(stack);

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Division by zero error.\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", expression[i]);
                    exit(1);
            }

            push(stack, result);
        }
    }

    if (isEmpty(stack)) {
        printf("Invalid expression.\n");
        exit(1);
    }
    int finalResult = pop(stack);
    free(stack->arr);
    free(stack);

    return finalResult;
}

int main() {
    char expression[100];
    printf("Enter a prefix expression: ");
    gets(expression);

    int result = evaluatePrefix(expression);
    printf("Result of the expression: %d\n", result);

    return 0;
}
