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
//��ӡ
void SeqListPrint(SL* ps);
//��ʼ��
void SeqListInit(SL* ps);
//β��
void SeqListPushBack(SL* ps, SLDataType x);
//βɾ
void SeqListPopBack(SL* ps);
//ͷ��
void SeqListPushFront(SL* ps, SLDataType x);
//ͷɾ
void SeqListPopFront(SL* ps);
//��������Ƿ��㹻������������
void SeqListCheck(SL* ps);
//�ҵ�ָ�����ݣ��ҵ��˷����±꣬û�ҵ�����-1
int SeqListFind(SL* ps, SLDataType x);
//��ָ��λ�ò�������
void SeqListInsert(SL* ps,int pos, SLDataType x);
//ɾ��posλ�õ�����
void SeqListDelete(SL* ps, int pos);


//�鲢
void gb(SL* ps1, SL* ps2);
//�������ϵĽ���
void Intersection(SL* ps1, SL* ps2);
//�������ϵĲ���
void Merge(SL* ps1, SL* ps2);
//�������ϵĲ
void Minus(SL* ps1, SL* ps2);






