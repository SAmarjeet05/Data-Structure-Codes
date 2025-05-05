#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x){
    if(l>r){
        printf("%d not found in the array.",x);
    }
    else{
        int mid = (l+r)/2;
        if(arr[mid] == x){
            printf("%d found at position %d",x,mid+1);
        }
        else if(arr[mid] > x){
            binarySearch(arr, l, mid-1, x);
        }
        else{
            binarySearch(arr, mid+1, r, x);
        }
        
    }
}
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
    binarySearch( arr, 0, n, x);
    
    return 0;
}