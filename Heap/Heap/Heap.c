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
	AdjustUp(php->a, php->size - 1);
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

//向下调整
void AdjustDown(HeapDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;  // 这里和链表里的长链表、短链表有异曲同工之妙，只不过这里只需要用到大的孩子
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)   //这里child+1要<php->size ，不可以=，因为数据个数是比下标大1
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
	//升序排序先建大堆还是小堆，先建大堆，因为如果小堆，比如找到了第一个最小的，找第二小的要重新建堆，很麻烦
	//但是如果大堆，找到最大的，和最后一个交换，然后向上调整 第 n-1 个，就很方便
	//同样的，降序排序先建小堆，最小的在堆顶，然后逐步放到最后。
	//可以理解为堆排序是和正常排序反着来，先排最后面的，逐步往前排

	//向上调整,时间复杂度是 N*log(N)
	// 每层节点少，调整次数少，节点多，调整次数多，且除了根节点，都要调整。
	//for (int i = 1;i < n;i++)
	//{
	//	AdjustUp(a, i);
	//}

	//向下调整, 时间复杂度是 N
	// 每层节点数量多，调整次数少，节点数量少，调整次数多。且跳过最后一层，接近一半的节点不要调整。
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