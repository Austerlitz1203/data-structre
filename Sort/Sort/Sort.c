#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Print(int *p,int n)
{
	for (int i = 0;i < n;i++)
		printf("%d ", p[i]);
}

//插入排序

// 1、直接插入排序
//时间复杂度O(N^2)
void InsertSort(int* p, int n)
{
	for (int i = 0;i < n - 1;i++)
	{
		int end = i;//end代表的是要排序的数字之前的那个数字的下标
		int temp = p[i + 1];//temp代表要排序的那个数字，那么for循环到n-2即可，这样就可以排序到下标n-1处
		while (end >= 0)//从后往前比较，不符合条件要--
		{
			if (p[end] > temp)
			{
				p[end + 1] = p[end];//不符合条件，该数字后移
				end--;
			}
			else
				break;//符合条件退出循环，找到了第一个比temp小的数字的下标
		}
		p[end + 1] = temp;//end代表的是第一个比temp小的下标，那么+1才是temp排序后的位置，而且end+1已经后移过了
	}                     //这一句不能写在else里面，是因为如果end=-1，那么不会进入while循环，也就白比较和后移了
}


//2、希尔排序
//每次排序间隔gap个位置，这样大的数很快到后面
void ShellSort(int *p,int n)
{
	int gap=n;
	while (gap > 1)
	{
		gap /= 2;//这样的好处是gap最后可以得到1
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


//堆排序，时间复杂度是N*log(2^N)
//规律：
// 1、下标：leftchild=parent*2+1
// 2、下标：rightchild=parent*2+2
// 3、下标：parent=(parent-1)/2
// 小堆：
// 每一个父亲节点都比其孩子节点小
// 大堆：
// 每一个父亲节点都比其孩子节点大
//要使用堆排序，那么树必须是小堆或者大堆

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//向下调整算法，时间复杂度 log2^N（2为敌，N代表元素个数）
//此算法前提是，根节点的左子树和右子树都是堆
//所以在排序的时候，不能直接使用向下调整算法，要从下往上使用此算法
void AdjustDown(int* p,int size,int root)
{
	int parent = root;//父亲的下标，从root开始向下调整
	int child = parent * 2 + 1;//孩子的下标
	while (child < size)//child可以等于size-1，因为最后一个下标就是size-1
	{
		if ((child+1) <= size-1 && p[child + 1] > p[child])
		{
			child += 1;//判断孩子节点哪个数据比较小
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

//升序
//此时必须要排大堆准备好
//      3
//    5    2
//   7  8  6  1
// 9 4  0
// 如上，如果小堆排好，那么就是0排到最前面，这样的话，就要从第二个元素开始排，那么堆结构完全破坏了
//    顺序就全乱了
// 而如果大堆排好，那么排序后 9 8 6 7 3 2 1 5 4 0 ，交换首尾 0 8 6 7 3 2 1 5 4 9，尾已经是最大，那么只需要排前n-1个
// 此时需要排的是 0 8 6 7 3 2 1 5 4
//       9
//     8   6 
//   7  3 2  1
// 5  4 0
// 变成了如下
//       0
//     8   6 
//   7  3 2  1
// 5  4
// 0的左子树依然是大堆，其右子树也依然是大堆结构，此时只需要一次向下调整算法就可以构成大堆
// 然后依次循环
//
void HeapSort(int *p,int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(p, size, i);//大堆
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
	//选择排序test
	//int arr[10] = { 10,45,23,3,67,87,55,4,66,59 };
	//InsertSort(arr, 10);
	//Print(arr, 10);

	//堆排序test
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	////AdjustDown(arr, 10, 0);
	//HeapSort(arr, 10);
	//Print(arr, 10);

	//
	return 0;
}