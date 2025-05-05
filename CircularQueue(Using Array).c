#include <stdio.h>

int front = -1, rear = -1;

void enqueue(int queue[], int data, int n) {
    if ((front == 0 && rear == n - 1) || (rear == (front - 1) % (n - 1))) {
        printf("Queue Overflow!!\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == n - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = data;
        printf("Inserted %d into the queue.\n", data);
    }
}

void dequeue(int queue[], int n) {
    if (front == -1) {
        printf("Queue Underflow!!\n");
    } else {
        int data = queue[front];
        printf("Deleted %d from the queue.\n", data);
        if (front == rear) {
            front = rear = -1;
        } else if (front == n - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}


void display(int queue[], int n) {
    if (front == -1) {
        printf("Queue Underflow!\n");
    } else {
        printf("Queue elements are: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (int i = front; i < n; i++) {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, data,n;
    printf("Enter the size of the queue: ");
    scanf("%d",&n);
    int queue[n];
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
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                enqueue(queue,data,n);
                break;
            case 2:
                dequeue(queue,n);
                break;
            case 3:
                display(queue,n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}