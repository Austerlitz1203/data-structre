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

//��ʼ��
void StrInit(SN* S);
//���Ƿ�Ϊ��,1Ϊ�գ�0Ϊ�ǿ�
int StrEmpty(SN* S);
//���ıȽ�
int StrCmp(SN* S, SN* T);
//next[]�Ĵ���
void find_next(SN* T, int* next);
//KMP�㷨Ѱ���Ӵ�T��λ��
int StrIndex(SN* S, SN* T, int pos);
//�����Ӵ�
void StrInsert(SN* S, int pos, SN* T);
//ɾ���Ӵ�
void StrDelete(SN* S, int pos, int len);
void StrDestory(SN* S);

