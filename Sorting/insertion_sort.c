#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *arr,int size){
    int key,j,loop = 0,comparison = 0;
    for(int i=1;i<size;i++){
        loop++;
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            comparison++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("%d\t%d\n\n",loop,comparison);
}

void printArr(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main(){
    int arr[]={85,45,70,30,25,35,40,5,10,17};
    int size=sizeof(arr)/sizeof(arr[0]);
    printArr(arr,size);
    insertionSort(arr,size);
    printArr(arr,size);
}