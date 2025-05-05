#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* front = NULL;
struct Node* rear = NULL;


void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("Inserted %d into the queue.\n", value);
}


void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!!\n");
        return;
    }
    struct Node* temp = front;
    int data = temp->data;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    printf("Deleted %d from the queue.\n", data);
    free(temp);
}


void display() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Elements of Queue are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
        }
    } while (choice != 4);

    return 0;
}