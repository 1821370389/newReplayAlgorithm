/* 选择排序 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAYSIZE 10
#define SUCCESS 0



/* 交换两个数 */
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return SUCCESS;
}

/* 打印数组 */
int printArray(int array[], int size)
{
    for(int idx = 0; idx < size; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
    return SUCCESS;
}
/* 冒泡排序 */
/* 选择排序*/
int selectionSort(int array[], int size)
{
    int temp; //用于记录最小值的位置
    for(int idx = 0; idx < ARRAYSIZE; idx++)
    {
        temp = idx;
        for(int jdx = idx + 1; jdx < ARRAYSIZE; jdx++)
        {
            if(array[temp] > array[jdx])
            {
                temp = jdx;
            }
        }
        if(temp != idx)
        {
            swap(&array[idx], &array[temp]);
        }
    }
    return SUCCESS;
}
/* 插入排序 */
int insertionSort(int array[], int size)
{
    int jdx;
    for(int idx = 1; idx < size; idx++)
    {   
        int temp = array[idx];
        jdx = idx - 1;
        while(jdx >= 0 && array[jdx] > temp)
        {
            array[jdx-- + 1] = array[jdx];
        }
        array[jdx + 1] = temp;
        printArray(array, size);
    }
}

/* 希尔排序 */
int shellSort(int array[], int size)
{
    int count = 1;
    int tempNum = size/2;
    while(tempNum > 0)
    {
        for(int idx = tempNum; idx < size; idx++)
        {
            int jdx = idx;
            int temp = array[jdx];
            while(jdx >= tempNum && array[jdx - tempNum] > temp)
            {
                array[jdx] = array[jdx - tempNum];
                jdx -= tempNum;
            }
            array[jdx] = temp;
        }
        tempNum /= 2;
    }
    return SUCCESS;
}

/* 快速排序 */
int quickSort(int array[], int start, int end)
{
    if(start >= end)
    {
        return SUCCESS;
    }
    /* 取array[start]为基准值，此处无用了，成为一个坑 */
    int referenceValue = array[start];
    int left = start, right = end;
    if(start < end)
    {
        while(left < right)
        {
            /* 找到右边第一个小于referenceValue的值 */
            while(left < right && array[right] >= referenceValue)
            {
                right--;
            }
            if(left < right)
            {
                /* 用array[right]填array[left](第一次时即array[start])的坑，同时在array[right]形成一个坑*/
                array[left++] = array[right];
            }
            /* 找到左边第一个大于referenceValue的值 */
            while(left < right && array[left] <= referenceValue)
            {
                left++;
            }
            if(left < right)
            {
                /* 用array[left]填array[right](即array[end])的坑，同时在array[left]形成一个坑*/
                array[right--] = array[left];
            }
        }
        /* 用referenceValue填最后的array[left]的坑 */
        array[left] = referenceValue;
    }
    /* 递归基准左边 */
    quickSort(array, start, left - 1);
    /* 递归急转右边 */
    quickSort(array, left + 1, end);

}

int main()
{
    int array[ARRAYSIZE] = {0};

    /* 随机数组 */
    srand(time(NULL));
    for (int idx = 0; idx < ARRAYSIZE; idx++)
    {
        array[idx] = rand() % 20 + 1;
    }
    /* 打印数组 */
    printf("排序前:\n");
    printArray(array, ARRAYSIZE);

#if 0
    /* 选择排序 */
    selectionSort(array, ARRAYSIZE);
#elif 0
    /* 插入排序 */
    insertionSort(array, ARRAYSIZE);
#elif 0
    /* 希尔排序 */
    shellSort(array, ARRAYSIZE);
#elif 1
    /* 快速排序 */
    quickSort(array,0,ARRAYSIZE-1);    
#endif

    /* 打印数组 */
    printf("排序后:\n");
    printArray(array, ARRAYSIZE);

    return SUCCESS;
}