#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// a. Create / Append node
void create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// b. Insert new node to the left of a target node
void insertLeft(int target, int newData) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node %d not found.\n", target);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    printf("Inserted %d to the left of %d.\n", newData, target);
}

// c. Delete node based on a specific value
void deleteValue(int val) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found.\n", val);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted %d from the list.\n", val);
}

// d. Display the contents of the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("DLL: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("DHRITI HALDIPUR\t 1WA25CS076 \t  17/11/26 \n");
    int choice, val, target;
    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Create / Insert End\n");
        printf("2. Insert Left of a Node\n");
        printf("3. Delete by Specific Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                create(val);
                break;
            case 2:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter new value to insert left: ");
                scanf("%d", &val);
                insertLeft(target, val);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteValue(val);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
