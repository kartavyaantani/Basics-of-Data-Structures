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
        printf("%c pushed onto the stack.\n", item);
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

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    struct Stack stack;
    initialize(&stack);
    
    if (decimal == 0) {
        push(&stack, 0);
    } else {
        while (decimal > 0) {
            int remainder = decimal % 2;
            push(&stack, remainder);
            decimal /= 2;
        }
    }

    printf("Binary representation: ");
    while (!isEmpty(&stack)) {
        int bit = pop(&stack);
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);
    int choice;
    char item;
    int number;
	printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Decimal to binary\n");
        printf("5. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to push onto the stack: ");
                scanf(" %c", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != '\0') {
                    printf("%c popped from the stack.\n", item);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                decimalToBinary(number);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
