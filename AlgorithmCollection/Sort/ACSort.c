//
//  ACSort.c
//  AlgorithmCollection
//
//  Created by TalMe on 2021/9/10.
//

#include "ACSort.h"

void printArray(int arr[], int count) {
    
    for(int i=0; i<count; i++)
        printf("%5d",arr[i]);    //输出排好序的数组
    printf("\n");
    
}

void testSort(void)
{
    int arr[] = {10, 9, 20, 4, 20, 433,1, 2};    //定义数组及变量为基本整型

    int count = sizeof(arr)/sizeof(int);
    printArray(arr, count);
    
//    quickSort(arr,0,count-1);    //调用qusort()函数进行排序
    
    bubbleSort(arr, count);
    
    printf("排序后的顺序是：\n");
    printArray(arr, count);
    
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int count)
{
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j ++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void quickSort(int arr[], int start, int end)
{
    int arrBase, arrMiddle;

    int tempStart = start,
        tempEnd = end;

    //对于这种递归的函数，内部必须要有一个函数返回的条件
    if(tempStart >= tempEnd)
        return;

    //10, 9, 20, 4, 20, 433,1, 2
    
    //拷贝一个基准值作为后面比较的参数
    arrBase = arr[start];
    while(start < end)
    {
        //后面的数和基准值进行比较，指针往前移动
        while(start < end && arr[end] > arrBase)
            end--;
        if(start < end)
        {
            //遇到比基准值小的，交换位置
            swap(&arr[start], &arr[end]);
            start++;
        }

        //前面的数和基准值进行比较，指针往后移动
        while(start < end && arr[start] < arrBase)
            start++;
        if(start < end)
        {
            //遇到比基准值大的，交换位置
            swap(&arr[start], &arr[end]);
            end--;
        }
    }
    
    //把基准值放到中间合适的位置
    arr[start] = arrBase;
    //设置分治排序的中间位置
    arrMiddle = start;


    printArray(arr, 8);
    
    //分治方法进行递归
    quickSort(arr, tempStart, arrMiddle-1);
    quickSort(arr, arrMiddle+1, tempEnd);
}


void quickSort1(int arr[], int start, int end) {
    int arrBase, arrMiddle;
    
    int tempStart = start, tempEnd = end;
    
    arrBase = arr[start];
    while (start < end) {
        while (start < end && arr[end] > arrBase) {
            end --;
        }
        
        if (start < end) {
            swap(&arr[start], &arr[end]);
            start ++;
        }
        
        while (start < end && arr[start] < arrBase) {
            start ++;
        }
        
        if (start < end) {
            swap(&arr[start], &arr[end]);
            end --;
        }
    }
    
    arr[start] = arrBase;
    arrMiddle = start;
    
    quickSort(arr, tempStart, arrMiddle - 1);
    quickSort(arr, arrMiddle + 1, tempEnd);
}
