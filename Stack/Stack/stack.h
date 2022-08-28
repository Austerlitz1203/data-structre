#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;
//初始化
void StackInit(ST* ps);
//销毁栈
void StackDestory(ST* ps);
//压栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);
//找到栈顶数据
STDataType StackTop(ST* ps);
//栈的里数据的多少
int StackSize(ST* ps);
//栈是否为空，1位空，0为非空
bool StackEmpty(ST* ps);

