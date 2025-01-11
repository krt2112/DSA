#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    struct Book* next;
};

struct Book* createBook(char* title) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    newBook->next = NULL;
    return newBook;
}

void insertBook(struct Book** head, char* title) {
    struct Book* newBook = createBook(title);
    if (*head == NULL) {
        *head = newBook;
        return;
    }
    struct Book* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBook;
}

void displayBooks(struct Book* head) {
    if (head == NULL) {
        printf("No books available.\n");
        return;
    }
    struct Book* temp = head;
    while (temp != NULL) {
        printf("Book: %s\n", temp->title);
        temp = temp->next;
    }
}

void deleteBook(struct Book** head, char* title) {
    struct Book *temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next; 
    } else {
        prev->next = temp->next; 
    }
    
    free(temp);
}


int main() {
    struct Book* head = NULL;
    int choice;
    char title[100];

    do {
        printf("\nMenu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; 
                insertBook(&head, title);
                break;
            case 2:
                displayBooks(head);
                break;
            case 3:
                printf("Enter book title to delete: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; 
                deleteBook(&head, title);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

