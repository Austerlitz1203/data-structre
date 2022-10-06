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

//��ӡ
void SListPrint(SLTNode* phead);
//�����µĵ�Ԫ
SLTNode* SListBuySLTNode(SLTDataType x);
//ͷ��
void SListPushFront(SLTNode** phead,SLTDataType x);
//β��
void SListPushBack(SLTNode** phead, SLTDataType x);
//ͷɾ
void SListPopFront(SLTNode** phead);
//βɾ
void SListPopBack(SLTNode** phead);
//��ѯ����
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//��posλ��֮ǰ��������
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
//���м�ɾ������
void SListErase(SLTNode** phead, SLTNode* pos);
//�������
void SListDestory(SLTNode** phead);

//�鲢
void merge(SLTNode* a, SLTNode* b, SLTNode** ret);
//��������
void test2(SLTNode** a);