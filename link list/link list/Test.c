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
	//Test2();

	//��1���鲢
	//��ʼ��la
	SLTNode* la = NULL;
	SListPushBack(&la, 1);
	SListPushBack(&la, 3);
	SListPushBack(&la, 6);
	SListPushBack(&la, 9);
	SListPushBack(&la, 10);

	//��ʼ��lb
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

	//��2������
	SLTNode* p1 = NULL;
	test2(&p1);
	SListPrint(p1);
	printf("\n");

	return 0;
}