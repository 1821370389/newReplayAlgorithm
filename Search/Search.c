#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

/* 宏定义再预处理阶段 被替换 */
#define MAX_SIZE 10

/* 状态码 */
enum STATUS_CODE
{
    SUCCESS = 0,
    NULL_PTR = -1,
    MALLOC_ERROR = -2,
    ILLEGAL_ACCESS = -3,
    UNDERFLOW = -4,

};

/* 
宏函数 无法调试 
不要超过十行
可以考虑用内联 
*/

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

/* 遍历查找 */
int search(int *array, int size, int value)
{
    /* 判空 */
    if (array == NULL)
    {
        return NULL_PTR;
    }

    /* 是否查找到 */
    int flag = 0;

    /* 遍历查找 */
    for (int idx = 0; idx < size; idx++)
    {
        if (array[idx] == value)
        {
            printf("找到了，下标为：%d\n", idx);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("没找到\n");
        return -1;
    }
    return SUCCESS;
    
}


/* 交换两个数 */
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
        // printf("第%d次排序:\n", idx);
        // printArray(array, size);
    }
}

/* 二分查找 */
int binarySearch(int *array, int size, int value)
{
    if (array == NULL)
    {
        return NULL_PTR;
    }
    while(array[size>>1] != value)
    {
        if(size == 1)
        {
            return -1;
        }
        while(array[size>>1] < value && size > 1)
        {
            size++;
            size >>= 1;
            array += size;
        }
        while(array[size>>1] > value && size > 1)
        {
            size++;
            size >>= 1;
        }
        
        
    }
    return 0;
}

int main()
{
    int array[MAX_SIZE] = {0};

    /* 设置随机数种子 */
    // srand(time(NULL));
    /* 生成随机数组 */
    for (int idx = 0; idx < MAX_SIZE; idx++)
    {
        array[idx] = rand() % 20 + 1;
    }
    bubbleSort(array, MAX_SIZE);
    printArray(array, MAX_SIZE);

    printf("请输入要查找的数字：");
    int value = 0;
    scanf("%d", &value);
    printf("%d\n", binarySearch(array, MAX_SIZE, value));
    search(array, MAX_SIZE, value);




    return SUCCESS;
}