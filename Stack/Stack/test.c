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

Test2()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	if (IsOutStack(a))
		printf("是正确的出栈序列！\n");
	else
		printf("不是正确的出栈序列！\n");

}
int main()
{
	//Test1();

	Test2();
	return 0;
}