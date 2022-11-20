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

	int arr[5] = { 0 };  // k�����ݵ�С��
	for (int i = 0;i < 5;i++)
	{
		fscanf(fout, "%d", &arr[i]);
		AdjustDown(arr, i);
	}

	int val = 0;
	while (fscanf(fout, "%d", &val) != NULL)//һ��һ����ȡ�����ڶѶ�Ԫ�أ���ô�ѶѶ�����Ǹ����֣��������µ���
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