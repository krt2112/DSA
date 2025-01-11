#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char name[100];
    char phoneNumber[20];
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(char* name, char* phoneNumber) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phoneNumber, phoneNumber);
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, char* name, char* phoneNumber) {
    if (root == NULL) {
        return createNode(name, phoneNumber);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phoneNumber);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, phoneNumber);
    }

    return root;
}


Node* search(Node* root, char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }

    return search(root->right, name);
}


Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, char* name) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = delete(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = delete(root->right, name);
    } else {
      
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);

        
        strcpy(root->name, temp->name);
        strcpy(root->phoneNumber, temp->phoneNumber);

        root->right = delete(root->right, temp->name);
    }

    return root;
}

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phoneNumber);
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice;
    char name[100], phoneNumber[20];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert New Contact\n");
        printf("2. Search for a Contact\n");
        printf("3. Delete a Contact\n");
        printf("4. Print Phone List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  
                printf("Enter Phone Number: ");
                fgets(phoneNumber, sizeof(phoneNumber), stdin);
                phoneNumber[strcspn(phoneNumber, "\n")] = 0; 
                root = insert(root, name, phoneNumber);
                printf("Contact inserted successfully!\n");
                break;

            case 2:
              
                printf("Enter Name to Search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; 
                Node* found = search(root, name);
                if (found) {
                    printf("Contact Found: Name: %s, Phone: %s\n", found->name, found->phoneNumber);
                } else {
                    printf("Contact not found.\n");
                }
                break;

            case 3:
                
                printf("Enter Name to Delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  
                root = delete(root, name);
                printf("Contact deleted successfully (if it existed).\n");
                break;

            case 4:
                
                printf("Phone List:\n");
                printInOrder(root);
                break;

            case 5:
                
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

