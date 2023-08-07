#include<stdio.h>

void swap(int *x, int *y) {
    
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify(int arr[],int size,int i){
    
    int largest = i; // Initialize largest as root
    int l = (2*i)+1; // Left child
    int r = (2*i)+2; // Right child

    // If left child is larger than root
    if(l<size && arr[l]>arr[largest]){
        largest = l;
    }
    // If right child is larger than largest so far
    if(r<size && arr[r]>arr[largest]){
        largest = r;
    }
    // If largest is not the root
    if(largest != i){
        
        //Swapping values of i and largest
        swap(&arr[i], &arr[largest]);

        // Recursive call
        maxHeapify(arr,size,largest);
    }
}

void heapSort(int arr[],int size){
    // Build heap (rearrange array)
    for(int i = (size/2)-1; i>=0; i--){
        maxHeapify(arr,size,i);
    }

    for(int i=size-1; i>=0; i--){
        // Move the current root to the end
        swap(&arr[0], &arr[i]);
        // Call heapify on the reduced heap
        maxHeapify(arr,i,0);
    }
}

void main(){
    int arr[] = {84,72,15};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    heapSort(arr,size);

    printf("\nAfter Sorting: ");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}