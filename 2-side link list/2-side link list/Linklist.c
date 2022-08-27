#define _CRT_SECURE_NO_WARNINGS 1
#include"Linklist.h"

LTNode* BuyLinkListData(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
LTNode* LinkListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void LinkListPrint(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
void LinkListPushFront(LTNode* phead, LTDataType x)
{
	//����
	assert(phead);
	LTNode* newnode = BuyLinkListData(x);
	LTNode* next = phead->next;
	//�������
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;

}
void LinkListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* pphead = phead;
	LTNode* Nnext = phead->next->next;
	LTNode* next = phead->next;
	
	//ɾ������
	pphead->next = Nnext;
	Nnext->prev = pphead;

	free(next);//ԭ��free(pphead->next);һֱ��������ֻ��free��ǰ�ĵ�ַ
}
void LinkListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyLinkListData(x);
	LTNode* Tail = phead->prev;

	//�������
	Tail->next = newnode;
	newnode->prev = Tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void LinkListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* Tail = phead->prev;
	LTNode* NewTail = Tail->prev;
	//ɾ������
	NewTail->next = phead;
	phead->prev = NewTail;
	free(Tail);
}
//��posǰ���������
void LinkListInsert(LTNode* phead, LTNode* pos, LTDataType x)
{
	assert(phead);
	assert(pos);
	LTNode* newnode = BuyLinkListData(x);
	LTNode* Prev = pos->prev;
	Prev->next = newnode;
	newnode->prev = Prev;
	newnode->next = pos;
	pos->prev = newnode;
}
//ɾ��posλ�õ�����
void LinkListErase(LTNode* phead, LTNode* pos)
{
	assert(phead);
	assert(pos);
	assert(phead->next != phead);
	LTNode* Prev = pos->prev;
	LTNode* Next = pos->next;
	Prev->next = Next;
	Next->prev = Prev;
}