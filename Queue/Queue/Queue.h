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

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestory(Queue* pq);
//入队
void QueuePush(Queue* pq, QDataType x);
//出队
void QueuePop(Queue* pq);
//取队头元素
QDataType QueueFront(Queue* pq);
//取队尾元素
QDataType QueueBack(Queue* pq);
//队列大小
int QueueSize(Queue* pq);
//队列是否为空
bool QueueEmpty(Queue* pq);
