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
//此算法前提是，左子树和右子树都是堆
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


//快速排序
//方法1、挖坑法
//但是单纯这样的算法无法排序，所以采用分治的思想。
//void QuickSort(int* p, int size)
//{
//	int* begin =p;
//	int* end = p + size - 1;
//	int* pit = begin;//坑位
//	int temp = *begin;//
//	while (begin < end)
//	{
//		while (begin < end && *end >= temp)//这里也要begin<end 假设 2  4  5 ，begin指向4，end指向5，那么--，然后end指向
//		{                                  //4，*end>3,end--,然后end指向2了，所以错位了，不行的，4应该是相遇处
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

//时间复杂度N*log(2^N)
//最好的情况是每次都二分
//最坏的情况是有序的情况下
//所以为了避免最坏的情况，用三数取中法确定temp
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
	if (left > right)//递归终止条件
	{
		return;
	}
	//用三数取中法要把取到的数和首元素交换
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
	//现在区间被分为了 [left,pit-1] pit [pit+1,right]
	//但是在这里如果直接递归的话，到最后只剩下比如10个数据，那么要递归很多很多次，不如最后的数据直接用其他办法排序
	//小区间优化法：
	if (pit - 1 - left > 10)
	{
		QuickSort(p, left, pit - 1);
	}
	else
		InsertSort(left, pit - 1 - left + 1);//左区间开始插入排序
	if (right - pit - 1 > 10)
	{
		QuickSort(p, pit + 1, right);
	}
	else
		InsertSort(pit+1, right - pit - 1 + 1);//右区间开始插入排序
}
//这种方法不需要像法2一样，最后left=right的时候去判断指向的那个值和*pit的大小关系，因为最后的情况下，指向的内容
//本身就是一个坑， 坑里面的内容早就被复制到上一个坑了，所以直接把*pit放进去就好
//而整个数组首位，即*pit，一开始就是一个坑，直接填内容，所以也不需要像法2，担心最后的时候，首位没有交换



//方法2：挖坑法2
//区别就是，两个指针，左边的遇到比*pit大的停下，右边遇到比*pit小的停下，交换两个数字，直到两个指针相等
void QuickSort2(int* p, int* left, int* right)
{
	if (left >= right)//递归终止条件
		return;

	int* index = GetMidIndex(p, left, right);
	Swap(index, left);

	int* begin = left;
	int* end = right;
	int* pit = begin;
	while (begin < end)
	{
		while (begin < end && *begin <= *pit)//“=”的原因：如果遇到 5 3 5 8 9 0  7 6 5 8这种情况，然后left指向第一个5
		{                                    //right指向最后一个5，然后没有“=”,那么循环不会进入，begin和end指向
			begin++;                         //的内容一直无限循环交换，陷入死循环
		}
		while (begin < end && *end >= *pit)
		{
			end--;
		}
		Swap(begin, end);
	}

	//这里必须要这样判断，英文如果到这种情况： 3 2 0 1 8 4 9 7 6 5 ，然后begin和end都指向8，那么此时要交换3和8，
	//这个时候，8>3,不可以这样，所以应该要交换3和8前面一个，然后begin指向的位置--（因为后面用的begin不是end）
	if (*begin < *pit)
		Swap(pit, begin);//交换相遇处的和开始的
	else
	{
		Swap(pit, begin - 1);
		begin--;
	}

	//被分成了     [left,begin -1] begin [begin+1,right]
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

//方法3：左右指针法
//思想：两个指针prev，cur，然后cur每次都要++，碰到比*pit小的，那么prev++，然后交换两个数字
void QuickSort3(int* p, int* left, int* right)
{
	int* index = GetMidIndex(p, left, right);
	Swap(index, left);

	int* prev = left;
	int* cur = left + 1;
	int* pit = left;

	while (cur <= right)
	{
		//只要cur指向的比*pit小，prev就会++，确保prev经过的都是比*pit小的
		if (*cur < *pit //巧妙之处在于：6 8 2 3 0 ，prev指向6，cur指向8，此时*cur>*pit,那么&&左边就是0，不会执行右边，prev也就不会++
			&& ++prev !=cur)//++prev==cur的情况下，那么就没有必要交换，因为两个一样
		{
			Swap(prev, cur);
		}
		cur++;
	}
	Swap(pit, prev);
	//现在分成了[left,prev-1] prev [prev+1,right]
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
	//选择排序test
	//int arr[10] = { 10,45,23,3,67,87,55,4,66,59 };
	//InsertSort(arr, 10);
	//Print(arr, 10);

	//堆排序test
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	////AdjustDown(arr, 10, 0);
	//HeapSort(arr, 10);
	//Print(arr, 10);

	//快速排序
	//int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	////QuickSort1(arr, arr, arr + 9);
	////QuickSort2(arr, arr, arr + 9);
	//QuickSort3(arr, arr,arr+9);
	//Print(arr, 10);

	//


	return 0;
}