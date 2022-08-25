#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListPrint(SLTNode* phead)
{
	//断言,无数据直接报错
	assert(phead != NULL);
	SLTNode* temp = phead;
	while (temp != NULL)
	{
		printf("%d->", (*temp).data);
		temp = (*temp).next;
	}

}

SLTNode* SListBuySLTNode(SLTDataType x)
{
	SLTNode* temp = (SLTNode*)malloc(sizeof(SLTNode));
	if (temp == NULL)
	{
		printf("malloc error!");
		exit(-1);
	}
	//数据域存储添加的数据，指针域为空
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void SListPushFront(SLTNode** phead, SLTDataType x)
{
	assert(phead);
	SLTNode* newnode= SListBuySLTNode(x);
	newnode->next = *phead;
	*phead = newnode;
}

void SListPushBack(SLTNode** phead, SLTDataType x)
{
	//断言
	assert(phead);
	SLTNode* newnode = SListBuySLTNode(x);
	SLTNode* temp = *phead;
	//没有数据的情况下
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	//有数据的情况下
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}

}

void SListPopFront(SLTNode** phead)
{
	assert(*phead != NULL);

	SLTNode* temp = *phead;
	*phead = temp->next;
	free(temp);
	temp = NULL;
}

void SListPopBack(SLTNode** phead)
{
	//断言
	assert(*phead != NULL);
	SLTNode* temp = *phead;
	//只有一个数据的情况下，free*phead且*phead要置成空
	if (temp->next == NULL)
	{
		free(temp);
		*phead = NULL;
	}
	//多个数据下，新的是最后一个数据的指针域要为空
	else
	{
		SLTNode* prev = NULL;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		free(temp);
		prev->next = NULL;
	}
}

//查询数据
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	//断言
	assert(phead != NULL);

	SLTNode* temp = phead;
	while(temp != NULL)
	{
		if (temp->data == x)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}
//在pos位置之前插入数据
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x)
{
	//断言，括号里的条件为假的时候报错，phead==NULL即假
	assert(phead);

	SLTNode* newnode = SListBuySLTNode(x);
	//pos是头节点的情况
	if (*phead == pos)
	{
		newnode->next = *phead;
		*phead = newnode;
	}
	else
	{
		SLTNode* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next=newnode;
	}

}
//在中间删除数据
void SListErase(SLTNode** phead, SLTNode* pos)
{
	//空链表，断言
	assert(*phead);
	//删除头节点
	if (pos == *phead)
	{
		*phead =pos->next;
		free(pos);
	}
	else
	{
		SLTNode* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
	}
}
void SListDestory(SLTNode** phead)
{
	//断言，空链表不需要销毁
	assert(*phead);

	SLTNode* temp = *phead;
	SLTNode* cur = *phead;
	while (temp!=NULL)
	{
		cur = temp->next;
		free(temp);
		temp = cur;
	}
	*phead = NULL;
}
