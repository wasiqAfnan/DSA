#include<stdio.h>
#include<conio.h>

void linear_search(int arr[],int elem){
    int flag = 0;
    int pos=0;
    for(int i = 0;i < 5;i++){
        if(arr[i] == elem){
            flag = 1;
            pos = i+1;
            break;
        }
    }
    if(flag == 0){
        printf("Element not present in the array!");
    }
    else{
        printf("%d is present in the %d position!",elem,pos);
    }
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

    linear_search(arr,elem);
    
}
