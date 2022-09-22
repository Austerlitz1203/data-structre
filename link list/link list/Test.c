#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void Test1()
{
	SLTNode* a=NULL;//一开始没有初始化为NULL，导致pushback里面最后一种情况，传过去的a是野指针，随意指，不是结构体的
	SListPushBack(&a, 5);
	SListPushBack(&a, 8);
	SListPushBack(&a, 456);
	//SListPopBack(&a);
	SListPushFront(&a, 5);
	SListPushFront(&a, 8);
	SListPushFront(&a, 456);
	SListPopFront(&a);
	SListPrint(a);
}


void Test2()
{
	SLTNode* a = NULL;
	SListPushBack(&a, 5);
	SListPushBack(&a, 8);
	SListPushBack(&a, 456);
	//SListPopBack(&a);
	SListPushFront(&a, 5);
	SListPushFront(&a, 8);
	SListPushFront(&a, 456);
	SListPopFront(&a);

	SLTNode* b=SListFind(a, 8);
	//SListInsert(&a, b, 20);

	SListErase(&a,b);
	SListDestory(&a);
	SListPrint(a);
}
int main()
{
	//Test1();
	//Test2();

	//（1）归并
	//初始化la
	SLTNode* la = NULL;
	SListPushBack(&la, 1);
	SListPushBack(&la, 3);
	SListPushBack(&la, 6);
	SListPushBack(&la, 9);
	SListPushBack(&la, 10);

	//初始化lb
	SLTNode* lb = NULL;
	SListPushBack(&lb, 2);
	SListPushBack(&lb, 3);
	SListPushBack(&lb, 4);
	SListPushBack(&lb, 5);
	SListPushBack(&lb, 6);
	SListPushBack(&lb, 8);
	SListPushBack(&lb, 14);

	SLTNode* ret = NULL;
	merge(la, lb, &ret);
	SListPrint(ret);
	printf("\n");

	//（2）正负
	SLTNode* p1 = NULL;
	test2(&p1);
	SListPrint(p1);
	printf("\n");

	return 0;
}