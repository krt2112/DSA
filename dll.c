#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Car {
    char model[50];
    struct Car* next;
    struct Car* prev;
};

struct Car* createCar(char* model) {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    strcpy(newCar->model, model);
    newCar->next = NULL;
    newCar->prev = NULL;
    return newCar;
}

void insertCar(struct Car** head, char* model) {
    struct Car* newCar = createCar(model);
    if (*head == NULL) {
        *head = newCar;
        return;
    }
    
    struct Car* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newCar;
    newCar->prev = temp;
}


void displayCars(struct Car* head) {
    struct Car* temp = head;
    while (temp != NULL) {
        printf("Car Model: %s\n", temp->model);
        temp = temp->next;
    }
}


void deleteCar(struct Car** head, char* model) {
    struct Car* temp = *head;

    while (temp != NULL && strcmp(temp->model, model) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Car model not found.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next; 
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

int main() {
    struct Car* head = NULL;

    insertCar(&head, "Toyota Camry");
    insertCar(&head, "Honda Accord");
    insertCar(&head, "Ford Mustang");

    printf("List of Car Models:\n");
    displayCars(head);

    printf("\nDeleting 'Honda Accord'\n");
    deleteCar(&head, "Honda Accord");

    printf("Updated List of Car Models:\n");
    displayCars(head);

    return 0;
}

