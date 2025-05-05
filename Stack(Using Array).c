#include <stdio.h>

int push(int stack[], int *top, int n, int data){
    if(*top == (n-1)){
        printf("Stack Overflow\n");
    }
    else{
        *top = *top + 1;
        stack[*top] = data;
        printf("%d inserted!\n",data);
    }
}
int pop(int stack[], int *top){
    if(*top == -1){
        printf("Stack Underflow\n");
    }
    else{
        int data = stack[*top];
        *top = *top - 1;
        printf("%d Popped!\n",data);
    }
}

int display(int stack[], int top){
    int n=top;
    if(top==-1){
        printf("Stack Empty!\n");
    }
    else{
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
    }
}

int main() {
    int n, choice, data, top=-1;
    printf("Enter the size of the stack: ");
    scanf("%d",&n);
    int stack[n];
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
            push(stack,&top,n,data);
            break;
            
            case 2:pop(stack,&top);
            break;
            
            case 3:display(stack,top);
            break;
        }
    }
    while(choice!=4);
    return 0;
}