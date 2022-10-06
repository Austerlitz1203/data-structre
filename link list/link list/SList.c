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
	printf("\n");

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
	free(pos);
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

//归并
void merge(SLTNode* a, SLTNode* b, SLTNode** ret)
{
	SLTNode* temp1 = a;
	SLTNode* temp2 = b;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->data < temp2->data)
		{
			SListPushBack(ret, temp1->data);
			temp1 = temp1->next;
		}
		else
		{
			SListPushBack(ret, temp2->data);
			temp2 = temp2->next;
		}
	}
	if (temp1)//temp2归并完了
	{
		while (temp1)
		{
			SListPushBack(ret, temp1->data);
			temp1 = temp1->next;
		}
	}
	else//temp1归并完了
	{
		while (temp2)
		{
			SListPushBack(ret, temp2->data);
			temp2 = temp2->next;
		}
	}
	return;
}

//正负分开，负数在前面，正数在后面，相对位置不变
void test2(SLTNode** a)
{
	//输入数据
	int x = 0;
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &x);
		SListPushBack(a, x);
	}
	//操作，arr存储数据
	int count = 0;
	SLTDataType arr[N] = { 0 };
	SLTNode* temp = *a;
	while (temp)
	{
		if (temp->data < 0)
			arr[count++] = temp->data;
		temp = temp->next;
	}
	temp = *a;
	while (temp)
	{
		if (temp->data > 0)
			arr[count++] = temp->data;
		temp = temp->next;
	}
	//重新赋值
	count = 0;
	temp = *a;
	while (temp)
	{
		temp->data = arr[count++];
		temp = temp->next;
	}
	return;
}
