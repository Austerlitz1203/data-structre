#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

int main()
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
	return 0;
}