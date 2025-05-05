#include<stdio.h>

int main() {
    int n, x, i, found = 0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("The array entered is as follows: \n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    
    printf("Enter the item to be searched: ");
    scanf("%d",&x);
    for(i=0;i<n;i++){
        if(arr[i]==x){
            found = 1;
            break;
        }
    }
    
    if(found == 1){
        printf("%d found at position %d",x,i+1);
    }
    else{
        printf("%d not found in the array.",x);
        
    }
    return 0;
}