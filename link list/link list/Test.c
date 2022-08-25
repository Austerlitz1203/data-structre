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
	Test2();
	return 0;
}