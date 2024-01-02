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
    int temp;
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
        swap(&array[idx], &array[temp]);
    }
    return SUCCESS;
}
/* 插入排序 */
int insertionSort(int array[], int size)
{
    for(int idx = 1; idx < size; idx++)
    {   
        int temp = array[idx];
        int jdx = idx - 1;
        while(jdx >= 0 && array[jdx] > temp)
        {
            array[jdx-- + 1] = array[jdx];
        }
        array[jdx + 1] = temp;
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
#elif 1
    /* 插入排序 */
    insertionSort(array, ARRAYSIZE);
#elif 1
    /* 希尔排序 */
    shellSort(array, ARRAYSIZE);
#endif

    /* 打印数组 */
    printf("排序后:\n");
    printArray(array, ARRAYSIZE);

    return SUCCESS;
}