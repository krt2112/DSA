#include <stdio.h>

typedef struct {
    int sid;
    char *cname;
    char *pname;
    int qty;
    int tam;
} sale;

// Function to swap two sale structures
void swap(sale *a, sale *b) {
    sale temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(sale s[], int low, int high) {
    int pivot = s[high].tam; // Choosing the last element as pivot
    int i = low - 1; // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        if (s[j].tam >= pivot) { // Change comparison for descending order
            i++; // Increment index of larger element
            swap(&s[i], &s[j]); // Swap
        }
    }
    swap(&s[i + 1], &s[high]); // Swap the pivot element with the element at i + 1
    return i + 1; // Return the partitioning index
}

// Quick Sort function
void quickSort(sale s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high); // Partitioning index
        quickSort(s, low, pi - 1); // Recursively sort elements before partition
        quickSort(s, pi + 1, high); // Recursively sort elements after partition
    }
}

int main() {
    int i;
    sale s[5];

    s[0].sid = 101;
    s[0].cname = "Suyog";
    s[0].pname = "Pen";
    s[0].qty = 5;
    s[0].tam = 50;

    s[1].sid = 102;
    s[1].cname = "Sujit";
    s[1].pname = "Box";
    s[1].qty = 5;
    s[1].tam = 55;

    s[2].sid = 103;
    s[2].cname = "Rohit";
    s[2].pname = "Pencil";
    s[2].qty = 3;
    s[2].tam = 60;

    s[3].sid = 104;
    s[3].cname = "Akash";
    s[3].pname = "Rubber";
    s[3].qty = 6;
    s[3].tam = 30;

    s[4].sid = 105;
    s[4].cname = "Shivam";
    s[4].pname = "Sharpner";
    s[4].qty = 4;
    s[4].tam = 40;

    quickSort(s, 0, 4); // Sorting the array using Quick Sort

    printf("Sorted Sales Data (Descending Order):\n");
    
    for(i=0; i<5; i++) {
        printf("\n SID : %d",s[i].sid);
        printf("\n C.NAME : %s",s[i].cname);
        printf("\n P.NAME : %s",s[i].pname);
        printf("\n QUANTITY : %d",s[i].qty);
        printf("\n TOTAL AMOUNT : %d\n",s[i].tam);
    }

    return 0;
}

