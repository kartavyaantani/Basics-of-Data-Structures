#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> // For toupper function

// Define the maximum length of the input string
#define MAX_LENGTH 100

// Define the stack structure
struct Stack {
    char data[MAX_LENGTH];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char c) {
    if (stack->top < MAX_LENGTH - 1) {
        stack->data[++stack->top] = c;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

// Function to check if a given string is a palindrome using a stack
bool isPalindrome(char* str) {
    struct Stack stack;
    initialize(&stack);
    int len = strlen(str);
    
    // Push each character of the string (converted to uppercase) onto the stack
    for (int i = 0; i < len; i++) {
        char c = toupper(str[i]);
        push(&stack, c);
    }
    
    // Pop characters from the stack and compare with the original string
    for (int i = 0; i < len; i++) {
        char c = pop(&stack);
        if (c != toupper(str[i])) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char input[MAX_LENGTH];
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    
    return 0;
}

