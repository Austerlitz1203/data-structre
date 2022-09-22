#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;
//��ʼ��
void StackInit(ST* ps);
//����ջ
void StackDestory(ST* ps);
//ѹջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);
//�ҵ�ջ������
STDataType StackTop(ST* ps);
//ջ�������ݵĶ���
int StackSize(ST* ps);
//ջ�Ƿ�Ϊ�գ�1λ�գ�0Ϊ�ǿ�
bool StackEmpty(ST* ps);
