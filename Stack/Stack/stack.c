#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"


void StackInit(ST* ps)
{
	assert(ps);
	//ps->data = NULL;
	//ps->capacity = ps->top = 0;

	ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->data == NULL)
	{
		perror("malloc fail!");
	}

	ps->capacity = ps->top = 0;
}
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

		STDataType* temp = (STDataType*)realloc(ps->data, newcapacity * sizeof(STDataType));
		if (temp == NULL)
		{
			printf("realloc fail!\n");
			exit(-1);
		}
		ps->data = temp;
		ps->capacity = newcapacity;
	}
	ps->data[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->data[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}




bool IsOutStack(int arr[N])
{
	ST stack;
	StackInit(&stack);
	int n = 1, count = 0;//n代表的是1-N的数值，count代表arr数组的下标
	StackPush(&stack, n++);//压栈
	while (count < N)
	{
		STDataType element = StackTop(&stack);
		if (element == arr[count])//栈顶元素等于数组中的当前值
		{
			StackPop(&stack);
			count++;
		}
		else
			StackPush(&stack, n++);//压栈

		//比如第一次输入1，那么第一次循环结束之后，无这个语句则栈为空，无法比较
		if (StackEmpty(&stack))
			StackPush(&stack, n++);
	}
	if (count == N)
	{
		return 1;
	}
	else
		return 0;
}