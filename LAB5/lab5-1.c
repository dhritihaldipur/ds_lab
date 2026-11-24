#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List 1 sorted successfully.\n");
}

void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List 1 reversed successfully.\n");
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    printf("DHRITI HALDIPUR\t 1WA25CS076 \t  17/11/26 \n");

    struct Node *list1 = NULL, *list2 = NULL;
    int choice, val;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List 1 & List 2\n");
        printf("6. Display Lists\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for List 1: ");
                scanf("%d", &val);
                insertEnd(&list1, val);
                break;
            case 2:
                printf("Enter value for List 2: ");
                scanf("%d", &val);
                insertEnd(&list2, val);
                break;
            case 3:
                sortList(list1);
                break;
            case 4:
                reverseList(&list1);
                break;
            case 5:
                list1 = concatenate(list1, list2);
                list2 = NULL;
                printf("Lists concatenated into List 1.\n");
                break;
            case 6:
                printf("List 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
