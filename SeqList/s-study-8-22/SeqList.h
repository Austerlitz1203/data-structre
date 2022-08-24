#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 100
typedef int SLDataType;

//动态顺序表
typedef struct SeqList
{
	SLDataType* a;  //一开始会想用数组，a[N]，但是这是静态的，长度无法确定，用指针，开辟空间，动态比较好
	int size;       //表示数组中存储了多少个数据
	int capacity;   //表示数组中可存放多少个数据
}SL;

//接口函数，命名风格更着STL走的
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

void SeqListCheck(SL* ps);
//找到指定数据，找到了返回下标，没找到返回-1
int SeqListFind(SL* ps, SLDataType x);
//在指定位置插入数据
void SeqListInsert(SL* ps,int pos, SLDataType x);
//删除pos位置的数据
void SeqListDelete(SL* ps, int pos);



