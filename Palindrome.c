#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Stack.h"

#define MAX_SIZE 100

// Function to check if a character is a letter (A-Z or a-z)
int isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    struct Stack stack;
    initialize(&stack);

    int len = strlen(str);

    // Push the letters (converted to uppercase) onto the stack
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (isLetter(c)) {
            push(&stack, toupper(c)); // Convert to uppercase
        }
    }

    // Compare the characters with the original string (converted to uppercase)
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (isLetter(c)) {
            char poppedChar = pop(&stack);
            if (poppedChar != toupper(c)) {
                return 0; // Not a palindrome
            }
        }
    }

    return 1; // It's a palindrome
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}

