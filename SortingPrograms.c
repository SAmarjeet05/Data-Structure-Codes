#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *queue = NULL;

int display(int arr[], int n){
    int i;
    printf("\nPrinting the sorted array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

int bubbleSort(int arr[], int n){
    int i, j, k;
    for(i=0;i<n;i++){
        printf("Pass %d ----\n",i);
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                printf("%d > %d Swapping.\n",arr[j],arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        for(k=0;k<n;k++){
        printf("%d ",arr[k]);
        }
        printf("\n");
    }
    display(arr,n);
    return 0;
}

int insertionSort(int arr[], int n){
    int i,j,k;
    for(i=1;i<n;i++){
        printf("Pass %d\n",i);
        j=i;
        while(j>=1 && arr[j] < arr[j-1]){
            printf("%d < %d Swapping Both.\n",arr[j],arr[j-1]);
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
            
        }
        for(k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
    }
    display(arr,n);
}

int push(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    
    if(queue == NULL || queue->data >= data){
        (queue==NULL)?printf("As %d > %d.\n", data,0):printf("As %d < %d.\n",data,queue->data);
        newnode->next = queue;
        queue = newnode;
    }
    else{
        struct node *temp = queue;
        while(temp->next != NULL && temp->next->data < data){
            temp=temp->next;
        }
        printf("As %d > %d.\n",data,temp->data);
        temp->next = newnode->next;
        temp->next = newnode;
    }
    struct node *current = queue;
    while(current->next!=NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("%d ",current->data);
    printf("\n");
}

int pop(){
    if(queue == NULL){
    }
    else{
        struct node *temp = queue;
        queue = queue->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}

int queueSort(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("Pass %d ----\n",i);
        push(arr[i]);
    }
    for(i=0;i<n;i++){
        arr[i] = pop();
    }
    display(arr,n);
}

int main() {
    int i, n=6, choice;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n],copyarr[n];

    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            copyarr[i] = arr[i];
    }
    printf("Unsorted array entered by you is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    do{
        //copying the unsorted array
        for(i=0;i<n;i++){
            arr[i] = copyarr[i];
        }
        printf("1. For Bubble Sort\n");
        printf("2. For Insertion Sort\n");
        printf("3. For Queue Sort\n");
        printf("4. For Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nSorting the array using Bubble Sort: \n");
            bubbleSort(arr,n);
            break;
            case 2:printf("\nSorting the array using Insertion Sort: \n");
            insertionSort(arr,n);
            break;
            case 3:printf("\nSorting the array using Queue: \n");
            queueSort(arr,n);
            break;
        }
    }
    while(choice!=4);
    return 0;
    
}