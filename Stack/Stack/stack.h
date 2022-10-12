#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define N 10

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;      //已有的数据个数
	int capacity; //容量
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

//

//1到N依次入栈，给一个序列，判断是否为正确出栈序列
bool IsOutStack(int arr[N]);
