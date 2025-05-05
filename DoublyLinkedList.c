#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *pre;
    int data;
    struct node *next;
};

struct node *head = NULL;
void display();

void insertBeg(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->pre = NULL;
    newnode->data = data;
    newnode->next = NULL;
    
    if(head==NULL){
        head = newnode;
        printf("Node inserted!!\n");
        display();
    }
    else{
        newnode->next = head;
        head->pre = newnode;
        head = newnode;
        printf("Node inserted!!\n");
        display();
    }
}

void deleteBeg(){
    if(head==NULL){
        printf("List is empty!!\n");
    }
    else{
        struct node *temp = head;
        head = head->next;
        head->pre = NULL;
        int data = temp->data;
        free(temp);
        printf("%d deleted!!\n",data);
        display();
    }
    
}

void insertMid(int data, int position){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->pre = NULL;
    newnode->data = data;
    newnode->next = NULL;
    
    if(head == NULL){
        printf("List is empty!!\n");
    }
    else{
        struct node *temp = head;
        while(temp->data != position && temp->next != NULL){
            temp = temp->next;
        }
        if(temp->data == position){
            newnode->next = temp->next;
            newnode->pre = temp;
            temp->next->pre = newnode;
            temp->next = newnode;
            printf("Node inserted!!\n");
            display();
        }
        else{
            printf("%d not found in the list!!\n",position);
        }
    }
    
}
void deleteMid(int position){
    if(head==NULL){
        printf("List is empty!!\n");
    }
    else{
        struct node *temp = head;
        while(temp->data != position && temp->next != NULL){
            temp =temp->next;
        }
        if(temp->data == position){
            struct node *temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next->pre = temp;
            int data = temp1->data;
            free(temp1);
            printf("%d deleted!!\n",data);
            display();
        }
        else{
            printf("%d not found in the list!!\n",position);
        }
    }
}

void display(){
    struct node *temp = head;
    if(head == NULL){
        printf("List is empty!!\n");
    }
    else{
        while(temp->next != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("%d\n\n",temp->data);
        
    }
}
    
int main() {
    int choice, data, position;
    while(1){
        printf("1 for Inserting a node.\n");
        printf("2 for Deleting a node.\n");
        printf("3 for Inserting node at a specified position.\n");
        printf("4 for Deleting node at a specified position.\n");
        printf("5 for Exit.\n");
        printf("Which operation do you need to perform: ");
        
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the data which needs to be inserted: ");
            scanf("%d",&data);
            insertBeg(data);
            break;
            case 2: deleteBeg();
            break;
            case 3: printf("Enter the data which needs to be inserted: ");
            scanf("%d",&data);
            printf("Enter the position after which the data should be inserted: ");
            scanf("%d",&position);
            insertMid(data, position);
            break;
            case 4: printf("Enter the position after which the data should be Deleted: ");
            scanf("%d",&position);
            deleteMid(position);
            break;
            case 5: printf("Exiting.....\n");
            break;
        }
        if(choice == 5){
            break;
        }
    }
    return 0;
}