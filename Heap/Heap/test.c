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

void TopK2()
{
	FILE* fout = fopen("test.txt", "w");
	if (fout == NULL)
	{
		perror("fopen fail::");
		return;
	}

	int n = 0, k = 0;
	int val = 0;
	printf("���������ݸ�����Ҫ���ǰk������>");
	scanf("%d%d", &n, &k);
	srand(time(NULL));
	for (int i = 0;i < n;i++)
	{
		val = rand();
		fprintf(fout, "%d\n", val);
		//fprintf(fout, "%d ", val);//����Ҳ�У�����Ҫ�пո���߻��з��ָ�
		//��ΪC���Զ�ȡ��ʱ��Ĭ���Կո���߻��������зָ���ǹ涨
	}
	fclose(fout);
	fout = NULL;

	FILE* pf = fopen("test.txt", "r");
	int* arr = (int*)malloc(sizeof(int) * k);// k�����ݵ�С��
	for (int i = 0;i < k;i++)
	{
		fscanf(pf, "%d", &arr[i]);
		AdjustDown(arr, i);
	}

	//int val = 0;
	while (fscanf(pf, "%d", &val) != EOF)//һ��һ����ȡ�����ڶѶ�Ԫ�أ���ô�ѶѶ�����Ǹ����֣��������µ���
	{
		if (val > arr[0])
		{
			arr[0] = val;
			AdjustDown(arr, 5);
		}
	}
	for (int i = 0;i < k;i++)
	{
		printf("%d\n", arr[i]);
	}

}

int main()
{
	//Test1();
	//Test2();
	//TopK();
	TopK2();
	return 0;
}