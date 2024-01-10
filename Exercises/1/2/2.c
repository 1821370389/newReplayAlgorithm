#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicArrayStack.h"


/* 判断入栈是否为左括号 */
#define RIGT_BRACKET(x) (x == '(' || x == '[' || x == '{')
/* 判断括号顺序是否正确 */
int isCorrect(char *s)
{
    /* 获取字符个数 */
    int slen = strlen(s);

    /* 初始化栈 */
    dynamicArrayStack *stack1;
    dynamicArrayStack *stack2;
    dynamicArrayStackInit(&stack1);
    dynamicArrayStackInit(&stack2);

    /* 将字符串中的字符入栈 */
    for(int i = 0; i < slen; i++)
    {
        printf("%c\n",s[i]);
        dynamicArrayStackPush(stack1,(ElemType)&s[i]);
    }
    
    // printf("%d\n",slen);
    /* 开始判断括号是否匹配 */
    /* 定义两个指针用于接收栈顶元素 */
    char *tempVal = NULL;
    char *tempVal2 = NULL;
    while(!dynamicArrayStackEmpty(stack1))
    {
        /* 取栈1顶元素 */
        dynamicArrayStackTop(stack1,(ElemType)&tempVal);
        /* 如果栈2为空，直接入栈2 */
        if(dynamicArrayStackEmpty(stack2))
        {

            dynamicArrayStackPop(stack1);
            dynamicArrayStackPush(stack2,(ElemType)tempVal);
            /* 若进栈的为左括号 直接跳出 */
            if(RIGT_BRACKET(*(char*)tempVal))
            {
                break;
            }
            continue;
        }
        /* 取栈2顶元素 */
        dynamicArrayStackTop(stack2,(ElemType)&tempVal2);
        /* 判断是否匹配 */
        if(*(char*)tempVal == '(' && *(char*)tempVal2 == ')' ||
            *(char*)tempVal == '[' && *(char*)tempVal2 == ']' || 
            *(char*)tempVal == '{' && *(char*)tempVal2 == '}')
        {
            /* 匹配，出栈2 */
            dynamicArrayStackPop(stack2);
        }
        else
        {
            /* 不匹配，入栈2 */
            dynamicArrayStackPush(stack2,(ElemType)tempVal);
            /* 若进栈的为左括号 直接跳出 */
            if(RIGT_BRACKET(*(char*)tempVal))
            {
                break;
            }
        }
        
        /* 出栈1 */
        dynamicArrayStackPop(stack1);
    }
    /* 栈1为空后，判断栈2是否为空 */
    if(dynamicArrayStackEmpty(stack2))
    {
        /* 栈2为空，括号匹配 */
        printf("yes\n");
    }
    else
    {
        /* 栈2不为空，括号不匹配 */
        printf("no\n");
    }

    /* 销毁栈 */
    dynamicArrayStackDestroy(stack1);
    dynamicArrayStackDestroy(stack2);
    return 0;

}

int main()
{
    char s[] = {'(',')','[','{','}',']'};
    isCorrect(s);
    return 0;
}