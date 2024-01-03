#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicArrayStack.h"


/* 判断括号顺序是否正确 */
int isCorrect(char *s)
{
    int slen = strlen(s);
    dynamicArrayStack *stack1;
    dynamicArrayStack *stack2;
    dynamicArrayStackInit(&stack1);
    dynamicArrayStackInit(&stack2);
    for(int i = 0; i < slen; i++)
    {
        printf("%c\n",s[i]);
        dynamicArrayStackPush(stack1,(ElemType)&s[i]);
    }
    
    printf("%d\n",slen);
    char *tempVal = NULL;
    char *tempVal2 = NULL;
    while(!dynamicArrayStackEmpty(stack1))
    {
        dynamicArrayStackTop(stack1,(ElemType)&tempVal);
        if(dynamicArrayStackEmpty(stack2))
        {
            dynamicArrayStackPop(stack1);
            dynamicArrayStackPush(stack2,(ElemType)tempVal);
            continue;
        }
        dynamicArrayStackTop(stack2,(ElemType)&tempVal2);
        if(*(char*)tempVal == '(' && *(char*)tempVal2 == ')' ||
            *(char*)tempVal == '[' && *(char*)tempVal2 == ']' || 
            *(char*)tempVal == '{' && *(char*)tempVal2 == '}')
        {
            dynamicArrayStackPop(stack2);
        }
        else
        {
            dynamicArrayStackPush(stack2,(ElemType)tempVal);
        }
        
        dynamicArrayStackPop(stack1);
    }
    if(dynamicArrayStackEmpty(stack2))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

}

int main()
{
    char s[] = {'(',')','[','{','}',']'};
    isCorrect(s);
}