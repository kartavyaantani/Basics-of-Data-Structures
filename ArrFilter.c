#include <stdio.h>

int main() {
    int n, k;

    // Input the number of elements in the array and k
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k <= 0 || k >= n) {
        printf("Invalid value of k. It should be between 1 and n-1.\n");
        return 1;
    }

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int stack[n]; // Use a stack to store elements to keep
    int top = -1; // Stack top

    for (int i = 0; i < n; i++) {
        while (top >= 0 && k > 0 && arr[i] > stack[top]) {
            // Pop elements from the stack as long as the current element is greater
            // and there are still elements to remove (k > 0).
            top--;
            k--;
        }
        stack[++top] = arr[i];
    }

    printf("Output: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}

