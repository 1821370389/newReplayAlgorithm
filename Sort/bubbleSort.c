#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 10
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
int printArray(int *array, int size)
{
    for(int idx = 0; idx < size; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
    return SUCCESS;
}
/* 冒泡排序 */
int bubbleSort(int *array, int size)
{
    int count = 0;
    for(int idx = size; idx > 1; idx--)
    {
        count = 1;
        for(int jdx = 1; jdx < idx; jdx++)
        {
            if(array[jdx] < array[jdx - 1])
            {
                swap(&array[jdx], &array[jdx - 1]);
                count = jdx + 1;
            }
        }
        idx = count;
        printf("第%d次排序:\n", idx);
        printArray(array, size);
    }
}

int main()
{
    int array[BUFFER_SIZE] = {0};//{1,2,3,5,6,7,8,9,10,11};

    /* 随机数组 */
    srand(time(NULL));
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        array[idx] = rand() % 20 + 1;
    }
    int size = sizeof(array) / sizeof(array[0]);
    /* 打印数组 */
    printf("排序前:\n");
    printArray(array, size);
    /* 冒泡排序 */
    bubbleSort(array, BUFFER_SIZE);
    /* 打印数组 */
    printf("排序后:\n");
    printArray(array, size);
}