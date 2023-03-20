#include<stdio.h>

void bubbleSort(int *arr,int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
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
    printf("Before Bubble Sort:\n");
    printArr(arr,size);
    bubbleSort(arr,size);
    printf("\nAfter Bubble Sort:\n");
    printArr(arr,size);
}