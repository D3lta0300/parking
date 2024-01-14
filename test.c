#include <stdio.h>

void addOneToMatrix(int n, int l, int matrix[][l]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            matrix[i][j] += 1;
        }
    }
}

void printMatrix(int n, int l, int matrix[][l]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example usage
    int n = 3; // Number of rows
    int l = 4; // Number of columns

    int myMatrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printf("Original Matrix:\n");
    printMatrix(n, l, myMatrix);

    addOneToMatrix(n, l, myMatrix);

    printf("\nMatrix after adding one to each element:\n");
    printMatrix(n, l, myMatrix);

    return 0;
}