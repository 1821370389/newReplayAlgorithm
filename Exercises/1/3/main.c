#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "doubleLinkList.h"

#define BUFFER_SIZE 10
#define DEFAULT_NUM 5
#define SUCCESS 0

/* 打印整形 */
int printInt(void *data)
{
    printf("%d ", *(int*)data);
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

/* 生成随机有序数组 */
static int* generateRandomArray(int n, int rangeL, int rangeR)
{
    srand(time(NULL));
    int *arr = (int*)malloc(sizeof(int) * n);
    for(int idx = 0; idx < n; idx++)
    {
        arr[idx] = rand() % (rangeR - rangeL + 1) + rangeL;
        printf("%d ", arr[idx]);
    }
    quickSort(arr, 0, n - 1);
    printf("\n");
    return arr;
            
}

/* 合并两个有序链表 */
static DoubleLinkList* merge(DoubleLinkList *list1, DoubleLinkList *list2)
{
#if 0
    DoubleLinkList *list3 = NULL;
    DoubleLinkListInit(&list3);
    DoubleLinkNode *node1 = list1->head->next;
    DoubleLinkNode *node2 = list2->head->next;
    while(node1 != NULL && node2 != NULL)
    {
        if(*(int*)node1->data < *(int*)node2->data)
        {
            DoubleLinkListTailInsert(list3, node1->data);
            node1 = node1->next;
        }
        else
        {
            DoubleLinkListTailInsert(list3, node2->data);
            node2 = node2->next;
        }
    }

    while(node1 != NULL)
    {
        DoubleLinkListTailInsert(list3, node1->data);
        node1 = node1->next;
    }
    while(node2 != NULL)
    {
        DoubleLinkListTailInsert(list3, node2->data);
        node2 = node2->next;
    }

    return list3;
#elif 1
    DoubleLinkNode *node1 = list1->head->next;
    int count = 1;
    while(node1 != NULL && list2->head->next != NULL)
    {
        if(*(int*)node1->data > *(int*)list2->head->next->data)
        {
            DoubleLinkListInsert(list1, count, list2->head->next->data);
            DoubleLinkListHeadDelete(list2);
        }
        else
        {
            node1 = node1->next;
        }
        count++;
    }
    while(list2->head->next != NULL)
    {
        DoubleLinkListInsert(list1, count++, list2->head->next->data);
        DoubleLinkListHeadDelete(list2);
    }
    return list1;
#elif 1
    DoubleLinkNode *node1 = list1->head->next;
    DoubleLinkNode *node2 = list2->head->next;
    int count = 1;
    while(node1 != NULL && node2 != NULL)
    {
        if(*(int*)node1->data > *(int*)node2->data)
        {
            DoubleLinkListInsert(list1, count, node2->data);
            node2 = node2->next;
        }
        else
        {
            node1 = node1->next;
        }
        count++;
    }
    while(node2 != NULL)
    {
        DoubleLinkListInsert(list1, count++, node2->data);
        node2 = node2->next;
    }
    return list1;
#endif
}

int main()
{
    int *arr = generateRandomArray(BUFFER_SIZE, 1, 40);
    DoubleLinkList *list = NULL;
    DoubleLinkListInit(&list);
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        DoubleLinkListTailInsert(list, &arr[idx]);
    }
    sleep(1);
    arr = generateRandomArray(DEFAULT_NUM, 1, 40);
    DoubleLinkList *list2 = NULL;
    DoubleLinkListInit(&list2);
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        DoubleLinkListTailInsert(list2, &arr[idx]);
    }
    printf("list:\n");
    DoubleLinkListTraverse(list, printInt);
    printf("\n");
    printf("list2:\n");
    DoubleLinkListTraverse(list2, printInt);
    printf("\n");

    /* 合并两个有序链表 */
    DoubleLinkList *list3 = merge(list, list2);
    printf("list3:\n");
    DoubleLinkListTraverse(list3, printInt);
    printf("\n");   

    /* 释放内存 */
    free(arr);
    DoubleLinkListDestroy(&list);
    DoubleLinkListDestroy(&list2);
    DoubleLinkListDestroy(&list3);
    return 0;
}