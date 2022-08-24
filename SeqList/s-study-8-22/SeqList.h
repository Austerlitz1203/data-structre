#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 100
typedef int SLDataType;

//��̬˳���
typedef struct SeqList
{
	SLDataType* a;  //һ��ʼ���������飬a[N]���������Ǿ�̬�ģ������޷�ȷ������ָ�룬���ٿռ䣬��̬�ȽϺ�
	int size;       //��ʾ�����д洢�˶��ٸ�����
	int capacity;   //��ʾ�����пɴ�Ŷ��ٸ�����
}SL;

//�ӿں���������������STL�ߵ�
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

void SeqListCheck(SL* ps);
//�ҵ�ָ�����ݣ��ҵ��˷����±꣬û�ҵ�����-1
int SeqListFind(SL* ps, SLDataType x);
//��ָ��λ�ò�������
void SeqListInsert(SL* ps,int pos, SLDataType x);
//ɾ��posλ�õ�����
void SeqListDelete(SL* ps, int pos);



