#include<stdio.h>

void selectionSort(int *arr,int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        
    }
}

void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void main(){
    int arr[]={10,14,2,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Before Selection Sort:\n");
    printArr(arr,size);
    selectionSort(arr,size);
    printf("\nAfter Selection Sort:\n");
    printArr(arr,size);
}