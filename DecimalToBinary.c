#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#define MAX_SIZE 32 
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
  
    int choice;
    int number;	          
    printf("Enter a decimal number: ");
    scanf("%d", &number);
    decimalToBinary(number);
          
    return 0;
}
