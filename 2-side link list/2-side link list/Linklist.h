#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;

typedef struct LinkListNode
{
	LTDataType data;
	struct LinkListNode* prev;
	struct LinkListNode* next;
}LTNode;

LTNode* BuyLinkListData(LTDataType x);
LTNode* LinkListInit();
void LinkListPrint(LTNode* phead);
void LinkListPushFront(LTNode* phead, LTDataType x);
void LinkListPopFront(LTNode* phead);
void LinkListPushBack(LTNode* phead, LTDataType x);
void LinkListPopBack(LTNode* phead);
//��posǰ���������
void LinkListInsert(LTNode* phead, LTNode* pos, LTDataType x);
//ɾ��posλ�õ�����
void LinkListErase(LTNode* phead, LTNode* pos);
//�ϸ�����ֻ�в����ɾ�����ɣ���Ϊͷ����ǲ��뵽��һ������ǰһ����β����ǲ��뵽�ڱ�λǰһ��
//ͷɾ����ɾ����һ�����ݣ�βɾ����ɾ���ڱ�λ��ǰһ��
void LinkListDestory(LTNode* phead);




