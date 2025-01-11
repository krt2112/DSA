#include <stdio.h>

typedef struct {
    int sid;
    char *cname;
    char *pname;
    int qty;
    int tam;
} sale;

void swap(sale *a, sale *b) {
    sale temp = *a;
    *a = *b;
    *b = temp;
}

int partition(sale s[], int low, int high) {
    int pivot = s[high].tam; 
    int i = low - 1; 
	int j;
    for (j = low; j < high; j++) {
        if (s[j].tam >= pivot) { 
            i++; 
            swap(&s[i], &s[j]); 
        }
    }
    swap(&s[i + 1], &s[high]); 
    return i + 1; 
}


void quickSort(sale s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high); 
        quickSort(s, low, pi - 1); 
        quickSort(s, pi + 1, high); 
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

    quickSort(s, 0, 4); 

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

