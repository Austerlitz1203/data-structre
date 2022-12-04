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
	AdjustUp(php->a, php->size - 1);
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
void AdjustUp(HeapDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
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
void AdjustDown(HeapDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;  // �����������ĳ�����������������ͬ��֮�ֻ��������ֻ��Ҫ�õ���ĺ���
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)   //����child+1Ҫ<php->size ��������=����Ϊ���ݸ����Ǳ��±��1
		{
			child++;
		}

		if (a[parent] > a[child])
		{
			Swap(&a[child], &a[parent]);
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
	AdjustDown(php->a, php->size, 0);
}

HeapDataType HeapTop(HP* php)
{
	assert(php);
	assert(!php->a);
	return php->a[0];
}

void HeapCreat(HP* php, HeapDataType* a, int len)
{
	assert(php);
	assert(a);
	php->a = (HeapDataType*)malloc(sizeof(HeapDataType) * len);
	if (php->a == NULL)
	{
		perror("malloc fail::");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HeapDataType) * len);
	php->size = php->capacity = len;

	for (int i = (len - 1 - 1) / 2;i >= 0;i--)
	{
		AdjustDown(php->a, php->size, i);
	}

}
void HeapSort(HeapDataType* a, int n)
{
	//���������Ƚ���ѻ���С�ѣ��Ƚ���ѣ���Ϊ���С�ѣ������ҵ��˵�һ����С�ģ��ҵڶ�С��Ҫ���½��ѣ����鷳
	//���������ѣ��ҵ����ģ������һ��������Ȼ�����ϵ��� �� n-1 �����ͺܷ���
	//ͬ���ģ����������Ƚ�С�ѣ���С���ڶѶ���Ȼ���𲽷ŵ����
	//�������Ϊ�������Ǻ������������������������ģ�����ǰ��

	//���ϵ���,ʱ�临�Ӷ��� N*log(N)
	// ÿ��ڵ��٣����������٣��ڵ�࣬���������࣬�ҳ��˸��ڵ㣬��Ҫ������
	//for (int i = 1;i < n;i++)
	//{
	//	AdjustUp(a, i);
	//}

	//���µ���, ʱ�临�Ӷ��� N
	// ÿ��ڵ������࣬���������٣��ڵ������٣����������ࡣ���������һ�㣬�ӽ�һ��Ľڵ㲻Ҫ������
	for (int i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;

	}

}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}