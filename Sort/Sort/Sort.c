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
//���㷨ǰ���ǣ������������������Ƕ�
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
int GetMidIndex(int* a, int* left, int* right)
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

void QuickSort(int* p, int* left,int* right)
{
	if (left > right)//�ݹ���ֹ����
	{
		return;
	}
	//������ȡ�з�Ҫ��ȡ����������Ԫ�ؽ���
	int* Index = GetMidIndex(p, left, right);
	Swap(left,Index);

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
		InsertSort(pit+1, right - pit - 1 + 1);//�����俪ʼ��������
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
			&& ++prev !=cur)//++prev==cur������£���ô��û�б�Ҫ��������Ϊ����һ��
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

	//��������
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	////QuickSort1(arr, arr, arr + 9);
	////QuickSort2(arr, arr, arr + 9);
	//QuickSort3(arr, arr,arr+9);
	//Print(arr, 10);

	//


	return 0;
}