#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *queue = NULL;

int enqueue(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    
    if(queue == NULL){
        queue = newnode;
        printf("%d inserted!\n",data);
    }
    else{
        struct node *temp = queue;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = newnode;
        printf("%d inserted!\n",data);
    }
}
int dequeue(){
    if(queue == NULL){
        printf("Queue Underflow\n");
    }
    else{
        struct node *temp = queue;
        queue = queue->next;
        int data = temp->data;
        free(temp);
        printf("%d deleted!!\n",data);
    }
}

int display(){
    if(queue == NULL){
        printf("Queue Empty!\n");
    }
    else{
        struct node *temp = queue;
        while(temp->next != NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
    
}

int main() {
    int choice, data;
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
            enqueue(data);
            break;
            
            case 2:dequeue();
            break;
            
            case 3:display();
            break;
        }
    }
    while(choice!=4);
    return 0;
}