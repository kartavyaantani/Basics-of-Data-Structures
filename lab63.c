#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TwoStacks {
    int top1;
    int top2;
    int arr[MAX_SIZE];
};

void init(struct TwoStacks *ts) {
    ts->top1 = -1;
    ts->top2 = MAX_SIZE;
}

void push1(struct TwoStacks *ts, int data) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = data;
    } else {
        printf("Stack 1 Overflow\n");
    }
}

void push2(struct TwoStacks *ts, int data) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = data;
    } else {
        printf("Stack 2 Overflow\n");
    }
}

int pop1(struct TwoStacks *ts) {
    if (ts->top1 >= 0) {
        return ts->arr[ts->top1--];
    } else {
        printf("Stack 1 is empty\n");
        return -1;
    }
}

int pop2(struct TwoStacks *ts) {
    if (ts->top2 < MAX_SIZE) {
        return ts->arr[ts->top2++];
    } else {
        printf("Stack 2 is empty\n");
        return -1;
    }
}

void display(struct TwoStacks *ts) {
    printf("Contents of Stack 1:\n");
    for (int i = 0; i <= ts->top1; i++) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");

    printf("Contents of Stack 2:\n");
    for (int i = MAX_SIZE - 1; i >= ts->top2; i--) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Push to Stack 1\n");
    printf("2. Push to Stack 2\n");
    printf("3. Pop from Stack 1\n");
    printf("4. Pop from Stack 2\n");
    printf("5. Display Stacks\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");
}

int main() {
    struct TwoStacks ts;
    init(&ts);
    int choice, data;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push to Stack 1: ");
                scanf("%d", &data);
                push1(&ts, data);
                break;
            case 2:
                printf("Enter data to push to Stack 2: ");
                scanf("%d", &data);
                push2(&ts, data);
                break;
            case 3:
                printf("Popped from Stack 1: %d\n", pop1(&ts));
                break;
            case 4:
                printf("Popped from Stack 2: %d\n", pop2(&ts));
                break;
            case 5:
                display(&ts);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
