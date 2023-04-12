#include<stdio.h>
#include<conio.h>

void binary_search(int arr[],int elem){
    int low = 0,mid,high = 5;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] > elem){
            high = mid - 1;
        }
        else if(arr[mid] < elem){
            low = mid + 1;
        }
        else if(arr[mid] == elem){
            printf("%d found in %d position",elem,mid+1);
            return;
        }
    }

    printf("Element not present in the array");
}

void main(){
    int arr[5],elem;
    // taking input form user
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %d Element:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter the Element you want to search:");
    scanf("%d",&elem);

    binary_search(arr,elem);
    
}