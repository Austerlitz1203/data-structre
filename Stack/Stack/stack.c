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
	int n = 1, count = 0;//n�������1-N����ֵ��count����arr������±�
	StackPush(&stack, n++);//ѹջ
	while (count < N)
	{
		STDataType element = StackTop(&stack);
		if (element == arr[count])//ջ��Ԫ�ص��������еĵ�ǰֵ
		{
			StackPop(&stack);
			count++;
		}
		else
			StackPush(&stack, n++);//ѹջ

		//�����һ������1����ô��һ��ѭ������֮������������ջΪ�գ��޷��Ƚ�
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