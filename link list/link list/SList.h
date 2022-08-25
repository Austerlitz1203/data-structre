#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
SLTNode* SListBuySLTNode(SLTDataType x);
void SListPushFront(SLTNode** phead,SLTDataType x);
void SListPushBack(SLTNode** phead, SLTDataType x);
void SListPopFront(SLTNode** phead);
void SListPopBack(SLTNode** phead);
//查询数据
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//在pos位置之前插入数据
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
//在中间删除数据
void SListErase(SLTNode** phead, SLTNode* pos);
//清空链表
void SListDestory(SLTNode** phead);