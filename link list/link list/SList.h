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
//��ѯ����
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//��posλ��֮ǰ��������
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
//���м�ɾ������
void SListErase(SLTNode** phead, SLTNode* pos);
//�������
void SListDestory(SLTNode** phead);