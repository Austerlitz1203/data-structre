#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct StrNode
{
	char* data;//由于串里的数据只能是字符串，所以不需要再typedef一个数据类型，后续不需要改
	int size;
	int capacity;
}SN;


void StrInit(SN* S);//初始化
int StrEmpty(SN *S);//串是否为空,1为空，0为非空
int StrCmp(SN *S, SN *T);
void find_next(SN* T, int* next);
int StrIndex(SN* S, SN* T,int pos);//寻找子串T的位置
void StrInsert(SN* S, int pos, SN* T);//插入子串
void StrDelete(SN* S, int pos, int len);//删除子串
void StrDestory(SN* S);

