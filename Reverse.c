#include <stdio.h>

void Reverse(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        // Swap elements pointed by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers
        start++;
        end--;
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    Reverse(arr, size);

    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
