#include <stdio.h>
#include "set.h"



int main()
{
    set *myset = NULL;
    setInit(&myset);
    /* 插入元素 */
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < 10; i++)
    {
        setInsert(myset, &arr[i]);
    }
    setInsert(myset, &arr[0]);
    /* 集合大小 */
    printf("set size: %d\n", setSize(myset));
    setForEach(myset);
    /* 集合是否为空 */
    if(setEmpty(myset))
    {
        printf("set is empty\n");
    }
    else
    {
        printf("set is not empty\n");
    }
    /* 集合是否包含某元素 */
    if(setContains(myset, &arr[0]))
    {
        printf("set contains %d\n", arr[0]);
    }
    else
    {
        printf("set not contains %d\n", arr[0]);
    }
    /* 删除元素 */
    setErase(myset, &arr[0]);
    /* 集合大小 */
    printf("set size: %d\n", setSize(myset));
    setForEach(myset);
    /* 返回第一个元素 */
    int first = setBegin(myset);
    printf("first element: %d\n", first);
    /* 返回最后一个元素 */
    int last = setEnd(myset);
    printf("last element: %d\n", last);

    /* 新建集合2 */
    set *myset2 = NULL;
    setInit(&myset2);
    /* 插入元素 */
    int arr2[] = {2,4,6,8,10,12,14,16,18,20};
    for(int i = 0; i < 10; i++)
    {
        setInsert(myset2, &arr2[i]);
    }
    printf("set2 size: %d\n", setSize(myset2));
    setForEach(myset2);
    /* 交集 */
    set *myset3 ;
    setInit(&myset3);
    setIntersect(myset, myset2,myset3);
    /* 集合大小 */
    printf("set3 size: %d\n", setSize(myset3));
    setForEach(myset3);
    /* 并集 */
    set *myset4 = NULL;
    setInit(&myset4);
    setUnion(myset, myset2, myset4);
    /* 集合大小 */
    printf("set4 size: %d\n", setSize(myset4));
    setForEach(myset4);

    /* 释放指针 */
    setClear(myset);
    setClear(myset2);
    setClear(myset3);
    setClear(myset4);

}