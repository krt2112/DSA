#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, value; 
} Element;

void fastTranspose(Element input[], Element output[], int totalElements) {
    int i;
    int rowTerms[MAX] = {0}, startingPos[MAX] = {0};

    for (i = 0; i < totalElements; i++) {
        rowTerms[input[i].col]++;
    }

    
    for (i = 1; i < MAX; i++) { 
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    for (i = 0; i < totalElements; i++) {
        int j = startingPos[input[i].col]++;
        output[j].row = input[i].col; 
        output[j].col = input[i].row;
        output[j].value = input[i].value; 
    }
}

void display(Element arr[], int totalElements) {
    int i;
    for (i = 0; i < totalElements; i++)
        printf("Row: %d, Column: %d, Value: %d\n", arr[i].row, arr[i].col, arr[i].value);
}

int main() {
    int totalElements = 0;
    int i;
    Element sparseMatrix[MAX], transposedMatrix[MAX];

    printf("Enter number of non-zero elements: ");
    scanf("%d", &totalElements);

    printf("Enter the elements of the sparse matrix (row col value):\n");
    for (i = 0; i < totalElements; i++) {
        scanf("%d %d %d", &sparseMatrix[i].row, &sparseMatrix[i].col, &sparseMatrix[i].value);
    }

    printf("Original Sparse Matrix:\n");
    display(sparseMatrix, totalElements);

    fastTranspose(sparseMatrix, transposedMatrix, totalElements);
    
    printf("\nFast Transposed Sparse Matrix:\n");
    display(transposedMatrix, totalElements);

    return 0;
}

