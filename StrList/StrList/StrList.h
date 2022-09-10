#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct StrNode
{
	char* data;//���ڴ��������ֻ�����ַ��������Բ���Ҫ��typedefһ���������ͣ���������Ҫ��
	int size;
	int capacity;
}SN;


void StrInit(SN* S);//��ʼ��
int StrEmpty(SN *S);//���Ƿ�Ϊ��,1Ϊ�գ�0Ϊ�ǿ�
int StrCmp(SN *S, SN *T);
void find_next(SN* T, int* next);
int StrIndex(SN* S, SN* T,int pos);//Ѱ���Ӵ�T��λ��
void StrInsert(SN* S, int pos, SN* T);//�����Ӵ�
void StrDelete(SN* S, int pos, int len);//ɾ���Ӵ�
void StrDestory(SN* S);

