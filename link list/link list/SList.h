#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 10
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//打印
void SListPrint(SLTNode* phead);
//创建新的单元
SLTNode* SListBuySLTNode(SLTDataType x);
//头插
void SListPushFront(SLTNode** phead,SLTDataType x);
//尾插
void SListPushBack(SLTNode** phead, SLTDataType x);
//头删
void SListPopFront(SLTNode** phead);
//尾删
void SListPopBack(SLTNode** phead);
//查询数据
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//在pos位置之前插入数据
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
//在中间删除数据
void SListErase(SLTNode** phead, SLTNode* pos);
//清空链表
void SListDestory(SLTNode** phead);

//归并
void merge(SLTNode* a, SLTNode* b, SLTNode** ret);
//正负分离
void test2(SLTNode** a);