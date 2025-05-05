#include <stdio.h>

int enqueue(int queue[], int *rear, int *front, int n, int data){
    if(*rear == (n-1)){
        printf("Queue Overflow\n");
    }
    else if(*rear == -1 && *front == -1){
        *rear = *rear + 1;
        *front = *front + 1;
        queue[*rear] = data;
        printf("%d inserted!\n",data);
    }
    else{
        *rear = *rear + 1;
        queue[*rear] = data;
        printf("%d inserted!\n",data);
    }
}
int dequeue(int queue[], int *rear, int *front){
    if(*front == -1){
        printf("Queue Underflow\n");
    }
    if(*front>*rear){
        *front = *rear = -1;
    }
    else{
        int data = queue[*front];
        *front = *front + 1;
        printf("%d Deleted!\n",data);
    }
}

int display(int queue[], int front, int rear){
    if(front==-1){
        printf("Queue Empty!\n");
    }
    else{
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
    }
    
}

int main() {
    int n, choice, data, front=-1, rear=-1;
    printf("Enter the size of the queue: ");
    scanf("%d",&n);
    int queue[n];
    do{
        printf("1. For Insert\n");
        printf("2. For Delete\n");
        printf("3. For Display\n");
        printf("4. For Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the data which needs to be inserted: ");
            scanf("%d",&data);
            enqueue(queue,&rear,&front,n,data);
            break;
            
            case 2:dequeue(queue,&rear,&front);
            break;
            
            case 3:display(queue,front,rear);
            break;
        }
    }
    while(choice!=4);
    return 0;
}