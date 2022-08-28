#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void Test1()
{
	ST a;
	StackInit(&a);
	StackPush(&a, 1);
	StackPush(&a, 2);
	StackPush(&a, 3);
	StackPush(&a, 4);
	printf("%d ", StackTop(&a));
	StackPop(&a);
	printf("%d ", StackTop(&a));
	StackPop(&a);

	StackPush(&a, 5);
	StackPush(&a, 6);
	while (!StackEmpty(&a))
	{
		printf("%d ", StackTop(&a));
		StackPop(&a);
	}
}

int main()
{
	Test1();
	return 0;
}