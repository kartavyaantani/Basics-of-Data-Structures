#include <stdio.h>
#include <stdlib.h>

void modifyValue(int *ptr) {
    int x;
    printf("Enter Differential Value: ");
    scanf("%d",&x);
    *ptr += x;
}

int *createArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
    return arr;
}

int main() {
    int num;
    printf("Enter Number: ");
    scanf("%d",&num);
    int *numPtr = &num;

    printf("Original value of num: %d\n", num);
    modifyValue(numPtr);
    printf("Value of num after modification: %d\n\n", num);

    int arraySize;
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int *dynamicArray = createArray(arraySize);

    printf("Dynamic Array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", dynamicArray[i]);
    }

    int value;
    printf("\n\nEnter Value: ");
    scanf("%d",&value);

    int *valuePtr = &value;
    int **ptrToPtr = &valuePtr;

    printf("Value: %d\n", value);
    printf("Value using pointer to pointer: %d\n", **ptrToPtr);
    free(dynamicArray);

	return 0;
}

