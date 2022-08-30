#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
void Test1()
{
	Queue a;
	QueueInit(&a);
	QueuePush(&a, 1);
	QueuePush(&a, 2);
	QueuePush(&a, 3);
	QueuePush(&a, 4);
	QueuePush(&a, 5);
	printf("%d\n", QueueSize(&a));
	//QueuePop(&a);
	//QueuePop(&a);
	//QueuePop(&a);
	//QueuePop(&a);
	//QueuePop(&a);
	//QueueDestory(&a);
	printf("%d\n", QueueFront(&a));
	printf("%d\n", QueueBack(&a));

	if (a.head)
	{
		QueueNode* cur = a.head;
		while (cur)
		{
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}

}

int main()
{
	Test1();
	return 0;
}