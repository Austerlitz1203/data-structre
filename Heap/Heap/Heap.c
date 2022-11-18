#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"


//��ʼ��
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

//����
void HeapPush(HP* php, HeapDataType x)
{
	assert(php);
	//����
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



//����
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

//���ϵ���
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

//���µ���
void AdjustDown(HP* php, int parent)
{
	assert(php);
	int child = parent * 2 + 1;  // �����������ĳ�����������������ͬ��֮�ֻ��������ֻ��Ҫ�õ���ĺ���
	while (child < php->size)
	{
		if (php->a[child] < php->a[child + 1] && child + 1 < php->size)   //����child+1Ҫ<php->size ��������=����Ϊ���ݸ����Ǳ��±��1
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