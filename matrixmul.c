#include <stdio.h>
#include <stdlib.h>
int** createMatrix(int rows, int cols) {
    int** matrix = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void readMatrix(int** matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the Dimensions of First matrix: ");
    scanf("%d %d", &rows1, &cols1);
    readMatrix(matrix1, rows1, cols1);

    printf("Enter the Dimensions of Second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    readMatrix(matrix2, rows2, cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    int** matrix1 = createMatrix(rows1, cols1);
    int** matrix2 = createMatrix(rows2, cols2);
    int** result = createMatrix(rows1, cols2);

    

    printf("First ");
    displayMatrix(matrix1, rows1, cols1);

    printf("Second ");
    displayMatrix(matrix2, rows2, cols2);

    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);

    printf("Product ");
    displayMatrix(result, rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);

return 0;
}