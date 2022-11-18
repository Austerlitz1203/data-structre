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
//在pos前面插入数据
void LinkListInsert(LTNode* phead, LTNode* pos, LTDataType x);
//删除pos位置的数据
void LinkListErase(LTNode* phead, LTNode* pos);
//严格来讲只有插入和删除即可，因为头插就是插入到第一个数据前一个，尾插就是插入到哨兵位前一个
//头删就是删除第一个数据，尾删就是删除哨兵位的前一个
void LinkListDestory(LTNode* phead);




