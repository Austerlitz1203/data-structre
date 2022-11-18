#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"


//初始化
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

//插入
void HeapPush(HP* php, HeapDataType x)
{
	assert(php);
	//扩容
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HeapDataType* ptr = (HeapDataType*)realloc(php->a, sizeof(HeapDataType) * newcapacity);
		if (ptr == NULL)
		{
			perror("realloc fali::");
			exit(-1);
		}
		php->a = ptr;
		php->capacity = newcapacity;
	}

	php->a[php->size] = x;
	php->size++;
	AdjustUp(php, php->size - 1);
}



//销毁
void HeapDestory(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void Swap(HeapDataType* a, HeapDataType* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//向上调整
void AdjustUp(HP* php, int child)
{
	assert(php);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (php->a[parent] < php->a[child])
		{
			Swap(&php->a[child], &php->a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void Print(HP* php)
{
	for (int i = 0;i < php->size;i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

//向下调整
void AdjustDown(HP* php, int parent)
{
	assert(php);
	int child = parent * 2 + 1;  // 这里和链表里的长链表、短链表有异曲同工之妙，只不过这里只需要用到大的孩子
	while (child < php->size)
	{
		if (php->a[child] < php->a[child + 1] && child + 1 < php->size)   //这里child+1要<php->size ，不可以=，因为数据个数是比下标大1
		{
			child++;
		}
		if (php->a[parent] < php->a[child])
		{
			Swap(&php->a[child], &php->a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	php->a[0] = php->a[php->size - 1];
	php->size--;
	AdjustDown(php, 0);
}

HeapDataType HeapTop(HP* php)
{

}
int HeapSize(HP* php);
bool HeapEmpty(HP* php);