#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, value;
} Element;

void simpleTranspose(Element input[], Element output[], int totalElements) {
	int i;
    for (i = 0; i < totalElements; i++) {
        output[i].row = input[i].col;
        output[i].col = input[i].row;
        output[i].value = input[i].value;
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
    Element sparseMatrix[MAX], transposedMatrix[MAX], fastTransposedMatrix[MAX];

    printf("Enter number of non-zero elements: ");
    scanf("%d", &totalElements);

    printf("Enter the elements of the sparse matrix (row col value):\n");
    for (i = 0; i < totalElements; i++) {
        scanf("%d %d %d", &sparseMatrix[i].row, &sparseMatrix[i].col, &sparseMatrix[i].value);
    }

    printf("Original Sparse Matrix:\n");
    display(sparseMatrix, totalElements);

    
    simpleTranspose(sparseMatrix, transposedMatrix, totalElements);
    printf("\nSimple Transposed Sparse Matrix:\n");
    display(transposedMatrix, totalElements);


    return 0;
}
