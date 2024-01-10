#ifndef __SET_H__
#define __SET_H__
#include "commnd.h"


/* 集合初始化 */
int setInit(set **pSet);
/* 集合清空 */
int setClear(set *pSet);
/* 集合添加元素 */
int setInsert(set *pSet, int* data);
/* 集合删除元素 */
int setErase(set *pSet, int* data);
/* 集合元素个数 */
int setSize(set *pSet);
/* 集合是否为空 */
int setEmpty(set *pSet);
/* 集合是否包含元素 */
int setContains(set *pSet, int *data);
/* 返回集合的第一个元素 */
int setBegin(set *pSet);
/* 返回集合的最后一个元素 */
int setEnd(set *pSet);
/* 遍历集合 */
int setForEach(set *pSet);
/* 返回交集 */
int setIntersect(set *pSet, set *pSet2, set *pSet3);
/* 返回并集 */
int setUnion(set *pSet, set *pSet2, set *pSet3);


#endif // !__SET_H__