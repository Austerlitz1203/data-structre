#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode * next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestory(Queue* pq);
//���
void QueuePush(Queue* pq, QDataType x);
//����
void QueuePop(Queue* pq);
//ȡ��ͷԪ��
QDataType QueueFront(Queue* pq);
//ȡ��βԪ��
QDataType QueueBack(Queue* pq);
//���д�С
int QueueSize(Queue* pq);
//�����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
