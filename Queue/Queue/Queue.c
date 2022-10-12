#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* temp = cur->next;
		free(cur);
		cur = temp;
	}
	pq->head = NULL;
	pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL && pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	QueueNode* cur = pq->head;
	free(cur);
	pq->head = next;
	if (pq->head == NULL)
		pq->tail = NULL;
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* cur = pq->head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}