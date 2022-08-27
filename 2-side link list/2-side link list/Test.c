#define _CRT_SECURE_NO_WARNINGS 1
#include"Linklist.h"

void Test1()
{
	LTNode* a = LinkListInit();
	LinkListPushFront(a, 5);
	LinkListPushFront(a, 4);
	LinkListPushFront(a, 3);
	LinkListPushFront(a, 2);
	LinkListPopFront(a);

	LinkListPushBack(a, 100);
	LinkListPopBack(a);
	LinkListInsert(a, a, 10);
	LTNode* b = a->next;
	LinkListErase(a, a->prev);
	LinkListPrint(a);
}


int main()
{
	Test1();
}