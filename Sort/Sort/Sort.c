#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
void Print(int* p, int n)
{
	for (int i = 0;i < n;i++)
		printf("%d ", p[i]);
}

//��������

// 1��ֱ�Ӳ�������
//ʱ�临�Ӷ�O(N^2)
void InsertSort(int* p, int n)
{
	for (int i = 0;i < n - 1;i++)
	{
		int end = i;//end�������Ҫ���������֮ǰ���Ǹ����ֵ��±�
		int temp = p[i + 1];//temp����Ҫ������Ǹ����֣���ôforѭ����n-2���ɣ������Ϳ��������±�n-1��
		while (end >= 0)//�Ӻ���ǰ�Ƚϣ�����������Ҫ--
		{
			if (p[end] > temp)
			{
				p[end + 1] = p[end];//�����������������ֺ���
				end--;
			}
			else
				break;//���������˳�ѭ�����ҵ��˵�һ����tempС�����ֵ��±�
		}
		p[end + 1] = temp;//end������ǵ�һ����tempС���±꣬��ô+1����temp������λ�ã�����end+1�Ѿ����ƹ���
	}                     //��һ�䲻��д��else���棬����Ϊ���end=-1����ô�������whileѭ����Ҳ�ͰױȽϺͺ�����
}


//2��ϣ������
//ÿ��������gap��λ�ã�����������ܿ쵽����
void ShellSort(int* p, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;//�����ĺô���gap�����Եõ�1
		//gap /= 3;
		for (int i = 0;i < n - gap;i++)
		{
			int end = i;
			int temp = p[i + gap];
			while (end >= 0)
			{
				if (p[end] > temp)
				{
					p[end + gap] = p[end];
					end -= gap;
				}
				else
					break;
			}
			p[end + gap] = temp;
		}
	}
}


//������ʱ�临�Ӷ���N*log(2^N)
//���ɣ�
// 1���±꣺leftchild=parent*2+1
// 2���±꣺rightchild=parent*2+2
// 3���±꣺parent=(parent-1)/2
// С�ѣ�
// ÿһ�����׽ڵ㶼���亢�ӽڵ�С
// ��ѣ�
// ÿһ�����׽ڵ㶼���亢�ӽڵ��
//Ҫʹ�ö�������ô��������С�ѻ��ߴ��

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//���µ����㷨��ʱ�临�Ӷ� log2^N��2Ϊ�У�N����Ԫ�ظ�����
//���㷨ǰ���ǣ������������������Ƕ�
//�����������ʱ�򣬲���ֱ��ʹ�����µ����㷨��Ҫ��������ʹ�ô��㷨
void AdjustDown(int* p, int size, int root)
{
	int parent = root;//���׵��±꣬��root��ʼ���µ���
	int child = parent * 2 + 1;//���ӵ��±�
	while (child < size)//child���Ե���size-1����Ϊ���һ���±����size-1
	{
		if ((child + 1) <= size - 1 && p[child + 1] > p[child])
		{
			child += 1;//�жϺ��ӽڵ��ĸ����ݱȽ�С
		}
		if (p[child] > p[parent])
		{
			Swap(&p[child], &p[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//����
//��ʱ����Ҫ�Ŵ��׼����
//      3
//    5    2
//   7  8  6  1
// 9 4  0
// ���ϣ����С���źã���ô����0�ŵ���ǰ�棬�����Ļ�����Ҫ�ӵڶ���Ԫ�ؿ�ʼ�ţ���ô�ѽṹ��ȫ�ƻ���
//    ˳���ȫ����
// ���������źã���ô����� 9 8 6 7 3 2 1 5 4 0 ��������β 0 8 6 7 3 2 1 5 4 9��β�Ѿ��������ôֻ��Ҫ��ǰn-1��
// ��ʱ��Ҫ�ŵ��� 0 8 6 7 3 2 1 5 4
//       9
//     8   6 
//   7  3 2  1
// 5  4 0
// ���������
//       0
//     8   6 
//   7  3 2  1
// 5  4
// 0����������Ȼ�Ǵ�ѣ���������Ҳ��Ȼ�Ǵ�ѽṹ����ʱֻ��Ҫһ�����µ����㷨�Ϳ��Թ��ɴ��
// Ȼ������ѭ��
//
void HeapSort(int* p, int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(p, size, i);//���
	}
	int end = size - 1;
	while (end)
	{
		Swap(&p[0], &p[end]);
		AdjustDown(p, end, 0);
		end--;
	}
}


//��������
//����1���ڿӷ�
//���ǵ����������㷨�޷��������Բ��÷��ε�˼�롣
//void QuickSort(int* p, int size)
//{
//	int* begin =p;
//	int* end = p + size - 1;
//	int* pit = begin;//��λ
//	int temp = *begin;//
//	while (begin < end)
//	{
//		while (begin < end && *end >= temp)//����ҲҪbegin<end ���� 2  4  5 ��beginָ��4��endָ��5����ô--��Ȼ��endָ��
//		{                                  //4��*end>3,end--,Ȼ��endָ��2�ˣ����Դ�λ�ˣ����еģ�4Ӧ����������
//			end--;
//		}
//		*pit=*end;
//		pit = end;
//
//		while (begin < end && *begin <= temp)
//		{
//			begin++;
//		}
//		*pit = *begin;
//		pit = begin;
//	}
//	*begin = temp;
//}

//ʱ�临�Ӷ�N*log(2^N)
//��õ������ÿ�ζ�����
//������������������
//����Ϊ�˱�����������������ȡ�з�ȷ��temp
int* GetMidIndex(int* a, int* left, int* right)
{
	int* mid = left + (right - left) / 2;
	if (*left < *mid)
	{
		if (*mid < *right)
		{
			return mid;
		}
		if (*left > *right)
		{
			return left;
		}
		else
			return right;
	}
	else//  *mid<*left
	{
		if (*left < *right)
		{
			return left;
		}
		if (*right < *mid)
		{
			return mid;
		}
		else
			return right;
	}
}

void QuickSort(int* p, int* left, int* right)
{
	if (left > right)//�ݹ���ֹ����
	{
		return;
	}
	//������ȡ�з�Ҫ��ȡ����������Ԫ�ؽ���
	int* Index = GetMidIndex(p, left, right);
	Swap(left, Index);

	int* begin = left;
	int* end = right;
	int* pit = begin;
	int temp = *begin;
	while (begin < end)
	{
		while (begin < end && *end >= temp)
		{
			end--;
		}
		*pit = *end;
		pit = end;

		while (begin < end && *begin <= temp)
		{
			begin++;
		}
		*pit = *begin;
		pit = begin;
	}
	*begin = temp;
	pit = begin;
	//�������䱻��Ϊ�� [left,pit-1] pit [pit+1,right]
	//�������������ֱ�ӵݹ�Ļ��������ֻʣ�±���10�����ݣ���ôҪ�ݹ�ܶ�ܶ�Σ�������������ֱ���������취����
	//С�����Ż�����
	if (pit - 1 - left > 10)
	{
		QuickSort(p, left, pit - 1);
	}
	else
		InsertSort(left, pit - 1 - left + 1);//�����俪ʼ��������
	if (right - pit - 1 > 10)
	{
		QuickSort(p, pit + 1, right);
	}
	else
		InsertSort(pit + 1, right - pit - 1 + 1);//�����俪ʼ��������
}
//���ַ�������Ҫ��2һ�������left=right��ʱ��ȥ�ж�ָ����Ǹ�ֵ��*pit�Ĵ�С��ϵ����Ϊ��������£�ָ�������
//�������һ���ӣ� �������������ͱ����Ƶ���һ�����ˣ�����ֱ�Ӱ�*pit�Ž�ȥ�ͺ�
//������������λ����*pit��һ��ʼ����һ���ӣ�ֱ�������ݣ�����Ҳ����Ҫ��2����������ʱ����λû�н���



//����2���ڿӷ�2
//������ǣ�����ָ�룬��ߵ�������*pit���ͣ�£��ұ�������*pitС��ͣ�£������������֣�ֱ������ָ�����
void QuickSort2(int* p, int* left, int* right)
{
	if (left >= right)//�ݹ���ֹ����
		return;

	int* index = GetMidIndex(p, left, right);
	Swap(index, left);

	int* begin = left;
	int* end = right;
	int* pit = begin;
	while (begin < end)
	{
		while (begin < end && *begin <= *pit)//��=����ԭ��������� 5 3 5 8 9 0  7 6 5 8���������Ȼ��leftָ���һ��5
		{                                    //rightָ�����һ��5��Ȼ��û�С�=��,��ôѭ��������룬begin��endָ��
			begin++;                         //������һֱ����ѭ��������������ѭ��
		}
		while (begin < end && *end >= *pit)
		{
			end--;
		}
		Swap(begin, end);
	}

	//�������Ҫ�����жϣ�Ӣ���������������� 3 2 0 1 8 4 9 7 6 5 ��Ȼ��begin��end��ָ��8����ô��ʱҪ����3��8��
	//���ʱ��8>3,����������������Ӧ��Ҫ����3��8ǰ��һ����Ȼ��beginָ���λ��--����Ϊ�����õ�begin����end��
	if (*begin < *pit)
		Swap(pit, begin);//�����������ĺͿ�ʼ��
	else
	{
		Swap(pit, begin - 1);
		begin--;
	}

	//���ֳ���     [left,begin -1] begin [begin+1,right]
	if (begin - 1 - left + 1 > 10)
	{
		QuickSort2(p, left, begin - 1);
	}
	else
		InsertSort(left, begin - 1 - left + 1);
	if (right - begin - 1 + 1 > 10)
	{
		QuickSort2(p, begin + 1, right);
	}
	else
		InsertSort(begin + 1, right - begin - 1 + 1);
}

//����3������ָ�뷨
//˼�룺����ָ��prev��cur��Ȼ��curÿ�ζ�Ҫ++��������*pitС�ģ���ôprev++��Ȼ�󽻻���������
void QuickSort3(int* p, int* left, int* right)
{
	int* index = GetMidIndex(p, left, right);
	Swap(index, left);

	int* prev = left;
	int* cur = left + 1;
	int* pit = left;

	while (cur <= right)
	{
		//ֻҪcurָ��ı�*pitС��prev�ͻ�++��ȷ��prev�����Ķ��Ǳ�*pitС��
		if (*cur < *pit //����֮�����ڣ�6 8 2 3 0 ��prevָ��6��curָ��8����ʱ*cur>*pit,��ô&&��߾���0������ִ���ұߣ�prevҲ�Ͳ���++
			&& ++prev != cur)//++prev==cur������£���ô��û�б�Ҫ��������Ϊ����һ��
		{
			Swap(prev, cur);
		}
		cur++;
	}
	Swap(pit, prev);
	//���ڷֳ���[left,prev-1] prev [prev+1,right]
	if (prev - 1 - left + 1 > 10)
	{
		QuickSort3(p, left, prev - 1);
	}
	else
		InsertSort(left, prev - 1 - left + 1);
	if (right - prev - 1 + 1 > 10)
	{
		QuickSort3(p, prev + 1, right);
	}
	else
		InsertSort(prev + 1, right - prev - 1 + 1);
}


//�鲢���� O(n*log2^n)
//Ҳ�Ƿ��ε�˼��
void MergeSort(int* p, int left, int right, int* ret)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	//��ʱ����Ϊ [left,mid]  [mid+1,right]
	MergeSort(p, left, mid, ret);
	MergeSort(p, mid + 1, right, ret);//��Ȼ�ݹ��ˣ��͵��з�������

	//��ʼ����
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;//index��ʾ��εݹ���Ҫ����Ŀ�ʼ���ݵ��±�
	while (begin1 <= end1 && begin2 <= end2)//���������������²Ž�������
	{
		if (p[begin1] < p[begin2])
		{
			ret[index++] = p[begin1++];
		}
		else
			ret[index++] = p[begin2++];
	}
	//��һ����ʣ������	
	while (begin1 <= end1)
	{
		ret[index++] = p[begin1++];
	}
	while (begin2 <= end2)
	{
		ret[index++] = p[begin2++];
	}
	//retֻ����ʱ��ţ����Ҫ�Ż�p���棬�����������
	for (int i = left;i <= right;i++)
	{
		p[i] = ret[i];
	}

}

//�ݹ��ڼ�������»ᵼ��ջ���
//�ݹ�ķǵݹ飺1��ֱ�Ӹ�ѭ�����򵥣�  2���������ݽṹ��ջģ��ݹ���̣�����һ�㣩
// 
//���ŵķǵݹ�����
int PartSort(int* p, int left, int right)
{
	int* temp = GetMidIndex(p, p + left, p + right);
	Swap(temp, p + left);//֮ǰһֱ�����������ｻ������p��temp��Ӧ�ý���p+left��ÿ�ο�������ĵ�һ��ֵ

	int begin = left;
	int end = right;
	int pit = begin;
	int temp1 = p[left];//Ҫ�Ƚϵ�ֵ����ÿ�αȽ��������λ�������������������λ
	while (begin < end)
	{
		while (begin < end && p[end] >= temp1)
		{
			end--;
		}
		p[pit] = p[end];
		pit = end;

		while (begin < end && p[begin] <= temp1)
		{
			begin++;
		}
		p[pit] = p[begin];
		pit = begin;
	}
	pit = begin;
	p[pit] = temp1;

	return pit;
}

void QuickSortNoR(int* p, int n)
{
	ST st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		int KeyIndex = PartSort(p, left, right);//һ���棬������һ���棬�ҵ�����������Ǹ�����λ��

		//[left KeyIndex-1] KeyIndex [KeyIndex+1,right]

		if (KeyIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, KeyIndex + 1);
		}

		if (KeyIndex - 1 > left)
		{
			StackPush(&st, KeyIndex - 1);
			StackPush(&st, left);
		}
	}
}

//�鲢����ǵݹ�
void MergeSortNoR(int* p, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		printf("malloc fail!");
		exit(-1);
	}
	int gap = 1;//gap��ʾÿһ�ι鲢��һ�����ݵ����ݸ���

	while (gap < n)
	{
		for (int i = 0;i < n;i += 2 * gap)
		{
			// [i,i+gap-1] [i+gap,i+2*gap-1]  [i+2*gap ����

			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//�Ұ����䲻���ڣ����ʱ��ǰ�涼�����ˣ�Ȼ��������䱾����������ģ����Խ�����һ�ּ���
			if (begin2 >= n)
			{
				break;
			}
			//�������˸�ֵ�������Ұ�����ֵ���ڰ˸�
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			//������䲻��gap�����������gap��������ݱ�����������ģ����Բ��ÿ���ȥ��ֱ�ӿ�����ǰһ��end2�����ݾͿ���
			//����Ҫ�ǿ�����end2,��Ϊ���漸��end2���ܱ����������Ұ��������ˣ����ܿ�����i+2*gap-1������

			int index = i;//temp�������Ҫ������ݵ��±�
			//��ʼ�鲢
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (p[begin1] <= p[begin2])
				{
					temp[index++] = p[begin1++];
				}
				else
				{
					temp[index++] = p[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				temp[index++] = p[begin1++];
			}
			while (begin2 <= end2)
			{
				temp[index++] = p[begin2++];
			}

			for (int j = i;j <= end2;j++)
			{
				p[j] = temp[j];
			}
		}
		gap *= 2;
	}
	free(temp);
}

//���Ը������������
void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(N * sizeof(int));
	int* a2 = (int*)malloc(N * sizeof(int));
	int* a3 = (int*)malloc(N * sizeof(int));
	int* a4 = (int*)malloc(N * sizeof(int));
	int* a5 = (int*)malloc(N * sizeof(int));
	int* a6 = (int*)malloc(N * sizeof(int));
	int* a7 = (int*)malloc(N * sizeof(int));
	int* a8 = (int*)malloc(N * sizeof(int));
	int* a9 = (int*)malloc(N * sizeof(int));

	for (int i = 0;i < N;i++)
	{
		a1[i] = rand();
		//a1[i]=i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	HeapSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	QuickSort(a4, a4 + 0, a4 + N - 1);
	int end4 = clock();

	int begin5 = clock();
	QuickSort2(a5, a5 + 0, a5 + N - 1);
	int end5 = clock();

	int begin6 = clock();
	QuickSort3(a6, a6 + 0, a6 + N - 1);
	int end6 = clock();

	int* temp1 = (int*)malloc(N * sizeof(int));
	int begin7 = clock();
	MergeSort(a7, 0, N - 1, temp1);
	int end7 = clock();

	int begin8 = clock();
	QuickSortNoR(a8, N);
	int end8 = clock();

	int begin9 = clock();
	MergeSortNoR(a9, N);
	int end9 = clock();


	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("HeapSort:%d\n", end3 - begin3);
	printf("QuickSort:%d\n", end4 - begin4);
	printf("QuickSort2:%d\n", end5 - begin5);
	printf("QuickSort3:%d\n", end6 - begin6);
	printf("MergeSort:%d\n", end7 - begin7);
	printf("QuickSortNoR:%d\n", end8 - begin8);
	printf("MergeSortNoR:%d\n", end9 - begin9);

	//free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
}


void BubbleSort(int* p, int n)
{
	for (int i = 0;i < n - 1;i++)//ð�ݴ�����������4�����ݣ�ʵ����ð�ݺ��������ݣ�ʣ�µľ�����С��
	{
		int exchange = 0;

		for (int j = 0;j < n - i - 1;j++) //����һ��ð�ݣ�������4�����ݣ���ôֻ��Ҫ�����������ɣ���Ϊ������߼��ǵ�ǰ���ݺ���һ�����ݱȽ�  
		{
			if (p[j] > p[j + 1])
			{
				Swap(&p[j], &p[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			return;
	}
	return;
}


// �о����ԣ�ֻ�ʺ����Σ���Χ���е�
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0;i < n;i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}

	int len = max - min + 1;
	int* countA = (int*)calloc(len, sizeof(int));
	if (!countA)
	{
		perror("calloc fail::");
		exit(-1);
	}

	//ͳ�ƴ���
	for (int i = 0;i < n;i++)
	{
		countA[a[i] - min]++; // ÿһ������ӳ�䵽����ȥ��Сֵ  a[i]-min 
	}

	// д��ԭ����
	int k = 0;
	for (int i = 0;i < len;i++)
	{
		while (countA[i]--)
		{
			a[k++] = i + min;
		}

	}
	free(countA);
}

int main()
{
	//int arr[10] = { 10,45,23,3,67,87,55,4,66,59 };
	//BubbleSort(arr, 10);
	//Print(arr, 10);

	//TestOP();

	//ѡ������test
	//int arr[10] = { 10,45,23,3,67,87,55,4,66,59 };
	//InsertSort(arr, 10);
	//Print(arr, 10);

	//������test
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	////AdjustDown(arr, 10, 0);
	//HeapSort(arr, 10);
	//Print(arr, 10);

	//��������
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	////QuickSort1(arr, arr, arr + 9);
	////QuickSort2(arr, arr, arr + 9);
	//QuickSort3(arr, arr,arr+9);
	//Print(arr, 10);

	//�鲢����
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0,100,99,88};
	//int size = sizeof(arr) / sizeof(arr[0]);
	//int* ret = (int*)malloc(size * sizeof(int));
	//MergeSort(arr, 0, size-1, ret);
	//Print(arr, size);

	//��������ǵݹ�
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	//QuickSortNoR(arr,10);
	//Print(arr, 10);

	//�鲢����ǵݹ�
	//int arr[] = { 3,5,2,7,8,6,1,9 ,4,5,11};
	//MergeSortNoR(arr, 11);
	//Print(arr, 11);

	//��������
	int arr[] = { 3,5,2,-7,8,-6,1,-9 ,4,-5,11 };
	CountSort(arr, 11);
	Print(arr, 11);


	return 0;
}