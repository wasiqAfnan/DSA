#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i <= size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int partition(int *arr, int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp=arr[end];
    arr[end]=arr[lb];
    arr[lb]=temp;

    return end;
}

void quickSort(int *arr,int lb,int ub)
{
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,ub);
    }
}

void main()
{
    int arr[] = {10, 2, 5, 7, 14, 1};
    int ub = 5;
    int lb = 0;
    printArr(arr, ub);
    quickSort(arr, lb, ub);
    printArr(arr, ub);
}