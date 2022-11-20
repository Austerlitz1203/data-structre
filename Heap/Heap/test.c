#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

Test1()
{
	int arr[] = { 10,78,99,45,67,45,0,77,34 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0;i < sizeof(arr) / sizeof(arr[0]);i++)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPop(&hp);
	Print(&hp);
}


Test2()
{
	int arr[] = { 10,78,99,45,67,45,0,77,34 };
	HP hp;
	HeapInit(&hp);
	HeapCreat(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapSort(hp.a, hp.size);
	Print(&hp);
}

TopK()
{
	FILE* fout = fopen("test.txt", "w");
	if (fout == NULL)
	{
		perror("fopen fail::");
		return;
	}

	int arr[5] = { 0 };  // k个数据的小堆
	for (int i = 0;i < 5;i++)
	{
		fscanf(fout, "%d", &arr[i]);
		AdjustDown(arr, i);
	}

	int val = 0;
	while (fscanf(fout, "%d", &val) != NULL)//一个一个读取，大于堆顶元素，那么把堆顶变成那个数字，并且向下调整
	{
		if (val > arr[0])
		{
			arr[0] = val;
			AdjustDown(arr, 5);
		}
	}
}

int main()
{
	//Test1();
	//Test2();
	TopK();
	return 0;
}