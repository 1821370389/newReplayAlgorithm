/* 集合的实现 */
#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "doubleLinkList.h"


/* 状态码 */
enum STATUS_CODE
{
    SUCCESS = 0,
    NULL_PTR = -1,
    MALLOC_ERROR = -2,
    ILLEGAL_ACCESS = -3,
    UNDERFLOW = -4,

};

/* 检查指针是否为空的宏函数 */
#define CHECK_NULL_POINTER(ptr)                 \
    do                                          \
    {                                           \
        if(ptr == NULL)                         \
        {                                       \
            return NULL_PTR;                    \
        }                                       \
    } while(0)  
/* 释放结点内存 */
#define FREE_NODE(node)                         \
    do                                          \
    {                                           \
        if(node != NULL)                        \
        {                                       \
            free(node);                         \
            node = NULL;                        \
        }                                       \
    } while(0)
/* 检测分配空间是否成功 */
#define CHECK_MALLOC_ERROR(ptr)                 \
    do                                          \
    {                                           \
        if(ptr == NULL)                         \
        {                                       \
            return MALLOC_ERROR;                \
        }                                       \
    } while(0)

/* 集合初始化 */
int setInit(set **pSet)
{
    DoubleLinkListInit(pSet);
    return SUCCESS;
}


/* 集合清空 */
int setClear(set *pSet)
{
    return DoubleLinkListDestroy(pSet);
}


/* 比较函数 */
static int compare(ELEMENTTYPE data1,ELEMENTTYPE data2)
{
    return *(int*)data1 - *(int*)data2;
}
/* 寻找插入位置 */
static int findInsertPos(set *pSet, int data)
{
    setNode *p = pSet->head->next;
    int count = 1;
    while (p != NULL)
    {
        if(compare(p->data,(ELEMENTTYPE)&data) < 0)
        {
            p = p->next;
            count++;
        }
        else 
        {
            break;
        }
    }
    return count;
}
/* 集合添加元素 */
int setInsert(set *pSet, int* data)
{
    /* 判空 */
    CHECK_NULL_POINTER(pSet);
    /* 插入 */
    int pop = findInsertPos(pSet,(int)*data);
    int* data2 = (int*)malloc(sizeof(int));
    CHECK_MALLOC_ERROR(data2);
    *data2 = 0;
    DoubleLinkListGet(pSet,pop,(ELEMENTTYPE)&data2);
    if(*data == *(int*)data2)
    {
        return SUCCESS;
    }
    return DoubleLinkListInsert(pSet,pop, (ELEMENTTYPE)data);
}


/* 判断是否相等 */
static int isSame(ELEMENTTYPE data1,ELEMENTTYPE data2)
{
    return *(int*)data1 == *(int*)data2 ? 1 : 0;
}
/* 集合删除元素 */
int setErase(set *pSet, int* data)
{
    return DoubleLinkListDeleteValue(pSet, (ELEMENTTYPE)data,isSame);
}


/* 集合元素个数 */
int setSize(set *pSet)
{
    /* 判空 */
    CHECK_NULL_POINTER(pSet);
    return pSet->count;
}


/* 集合是否为空 */
int setEmpty(set *pSet)
{
    /* 判空 */
    return pSet->count == 0 ? 1 : 0;
}


/* 集合是否包含元素 */
int setContains(set *pSet, int* data)
{
    /* 判空 */
    CHECK_NULL_POINTER(pSet);
    int* data2 = (int*)malloc(sizeof(int));
    CHECK_MALLOC_ERROR(data2);
    *data2 = 0;
    int pop = findInsertPos(pSet,(int)*data);
    // printf("pop = %d\n",pop);
    DoubleLinkListGet(pSet,pop,(ELEMENTTYPE)&data2);
    // printf("data2 = %d\n",*(int*)data2);
    // printf("data = %d\n",(int)*data);
    if((int)*data == *(int*)data2)
    {
        return 1;
    }

    return 0;
}


/* 返回集合的第一个元素 */
int setBegin(set *pSet)
{
    int* data = (int*)malloc(sizeof(int));
    CHECK_MALLOC_ERROR(data);
    *data = 0;
    DoubleLinkListGet(pSet,1,(ELEMENTTYPE)&data);
    return *data;
}


/* 返回集合的最后一个元素 */
int setEnd(set *pSet)
{
    int* data = (int*)malloc(sizeof(int));
    CHECK_MALLOC_ERROR(data);
    *data = 0;
    DoubleLinkListGet(pSet,pSet->count,(ELEMENTTYPE)&data);
    return *data;
}

/* 打印函数 */
static int printInt(ELEMENTTYPE data)
{
    printf("%d \n",*(int*)data);
    return SUCCESS;
}
/* 遍历集合 */
int setForEach(set *pSet)
{
    return DoubleLinkListTraverse(pSet,printInt);
}


/* 返回交集 */
int setIntersect(set *pSet, set *pSet2, set *pSet3)
{
    set *pTempSet = (set*)malloc(sizeof(set));
    CHECK_MALLOC_ERROR(pTempSet);
    setInit(&pTempSet);
    int* data = (int*)malloc(sizeof(int));
    CHECK_MALLOC_ERROR(data);
    *data = 0;
    int pop = 1;
    while(pop <= pSet->count)
    {
        DoubleLinkListGet(pSet,pop++,(ELEMENTTYPE)&data);
        if(setContains(pSet2,data))
        {
            setInsert(pTempSet,data);
        }
    }
    *pSet3 = *pTempSet;
    FREE_NODE(pTempSet);
    return SUCCESS;

}
/* 返回并集 */
int setUnion(set *pSet, set *pSet2, set *pSet3)
{
    set *pTempSet = (set*)malloc(sizeof(set));
    CHECK_MALLOC_ERROR(pTempSet);
    setInit(&pTempSet);
    int* data = (int*)malloc(sizeof(int));
    CHECK_MALLOC_ERROR(data);
    *data = 0;
    int pop = 1;
    while(pop <= pSet->count)
    {
        DoubleLinkListGet(pSet,pop++,(ELEMENTTYPE)&data);
        setInsert(pTempSet,data);
    }
    pop = 1;
    while(pop <= pSet2->count)
    {
        DoubleLinkListGet(pSet2,pop++,(ELEMENTTYPE)&data);
        setInsert(pTempSet,data);
    }
    *pSet3 = *pTempSet;
    FREE_NODE(pTempSet);
    return SUCCESS;

}