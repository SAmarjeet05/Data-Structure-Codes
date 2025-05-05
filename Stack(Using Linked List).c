#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *stack = NULL;

int push(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    
    if(stack==NULL){
        stack = newnode;
        printf("%d inserted!!\n",data);
    }
    else{
        newnode->next = stack;
        stack = newnode;
        printf("%d inserted!!\n",data);
    }
}
int pop(){
    if(stack == NULL){
        printf("Stack Underflow\n");
    }
    else{
        struct node *temp = stack;
        stack = temp->next;
        int data = temp->data;
        free(temp);
        printf("%d Popped!\n",data);
    }
}

int display(){
    if(stack == NULL){
        printf("Stack Empty!\n");
    }
    else{
        struct node *temp = stack;
        while(temp->next != NULL){
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}

int main() {
    int choice, data;
    do{
        printf("1. For Push\n");
        printf("2. For Pop\n");
        printf("3. For Display\n");
        printf("4. For Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the data which needs to be inserted: ");
            scanf("%d",&data);
            push(data);
            break;
            
            case 2:pop();
            break;
            
            case 3:display();
            break;
        }
    }
    while(choice!=4);
    return 0;
}