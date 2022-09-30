#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Print(int *p,int n)
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
void ShellSort(int *p,int n)
{
	int gap=n;
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
//���㷨ǰ���ǣ����ڵ�������������������Ƕ�
//�����������ʱ�򣬲���ֱ��ʹ�����µ����㷨��Ҫ��������ʹ�ô��㷨
void AdjustDown(int* p,int size,int root)
{
	int parent = root;//���׵��±꣬��root��ʼ���µ���
	int child = parent * 2 + 1;//���ӵ��±�
	while (child < size)//child���Ե���size-1����Ϊ���һ���±����size-1
	{
		if ((child+1) <= size-1 && p[child + 1] > p[child])
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
void HeapSort(int *p,int size)
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
int main()
{
	//ѡ������test
	//int arr[10] = { 10,45,23,3,67,87,55,4,66,59 };
	//InsertSort(arr, 10);
	//Print(arr, 10);

	//������test
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	////AdjustDown(arr, 10, 0);
	//HeapSort(arr, 10);
	//Print(arr, 10);

	//
	return 0;
}