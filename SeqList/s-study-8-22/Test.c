#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SeqListTest()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPushBack(&s1, 6);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);
}

void SeqListTest2()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushFront(&s1, 4);
	SeqListPushFront(&s1, 5);
	SeqListPushFront(&s1, 6);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopFront(&s1);

	SeqListInsert(&s1, 2, 90);
	SeqListPrint(&s1);
	printf("\n%d",SeqListFind(&s1, 5));
	
}
void SeqListTest3()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 34);
	SeqListPushBack(&s1, 66);
	SeqListPushBack(&s1, 8);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPushBack(&s1, 6);
	SeqListDelete(&s1, 3);
	SeqListPrint(&s1);
}

void SeqListTest4()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPushBack(&s1, 6);
	SeqListPrint(&s1);
	SL s2;
	SeqListInit(&s2);
	SeqListPushBack(&s2, 4);
	SeqListPushBack(&s2, 5);
	SeqListPushBack(&s2, 6);
	SeqListPushBack(&s2, 7);
	SeqListPushBack(&s2, 8);
	SeqListPushBack(&s2, 9);
	SeqListPrint(&s2);

	gb(&s1, &s2);
	Intersection(&s1, &s2);
	Merge(&s1, &s2);
	Minus(&s1, &s2);
	
}

int main()
{

	//SeqListTest();
	//SeqListTest2();
	//SeqListTest3();
	SeqListTest4();
	return 0;
}