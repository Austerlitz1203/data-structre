#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void Test1()
{
	SLTNode* a=NULL;//һ��ʼû�г�ʼ��ΪNULL������pushback�������һ�����������ȥ��a��Ұָ�룬����ָ�����ǽṹ���
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