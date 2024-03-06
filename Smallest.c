#include <stdio.h>
#include <stdlib.h>

int Smallest(int *arr, int size) {
    int min = *arr; 
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i); 
        }
    }
    return min;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    int smallest = Smallest(arr, size);


    printf("The smallest element in the array is: %d\n", smallest);

    free(arr);

    return 0; 
}

