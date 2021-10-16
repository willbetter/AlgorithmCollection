//
//  ACSearch.c
//  AlgorithmCollection
//
//  Created by TalMe on 2021/9/11.
//

#include "ACSearch.h"
#include "ACSort.h"


void testSearch(void) {
    int arr[] = {10, 9, 20, 4, 20, 433,1, 2};    //定义数组及变量为基本整型

    int count = sizeof(arr)/sizeof(int);
    
    quickSort(arr, 0, count - 1);
    int index = binarySearch(arr, count, 20);
    
    printf("search index is %d", index);
    
}

int binarySearch(int arr[], int count, int searchValue) {
    
    
    int middle = 0;
    
    int low = 0, heigh = count -1;
    while (low <= heigh) {
        middle = (low + heigh) / 2;
        if (arr[middle] == searchValue) {
            return middle;
        }else if(arr[middle] > searchValue) {
            heigh = middle - 1;
        }else {
            low = middle + 1;
        }
    }
    return -1;
}

int binarySearch1(int arr[], int count, int searchValue) {
    
    int middle = 0;
    
    int low = 0, heigh = count -1;
    
    while (low <= heigh) {
        middle = (low + heigh)/2;
        if (arr[middle] >= searchValue) {
            low = middle - 1;
        }else if (arr[middle] <= searchValue) {
            heigh = middle + 1;
        }else {
            return middle;
        }
    }
    return -1;
}

