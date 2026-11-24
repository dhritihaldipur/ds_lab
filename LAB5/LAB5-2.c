#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
struct Node *front = NULL, *rear = NULL;

// Stack Operations
void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d to Stack.\n", val);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d from Stack.\n", top->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Queue Operations
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d to Queue.\n", val);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow.\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued %d from Queue.\n", front->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("DHRITI HALDIPUR\t 1WA25CS076 \t  17/11/26 \n");
    int choice, val;
    while (1) {
        printf("\n--- STACK & QUEUE MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
