#define _CRT_SECURE_NO_WARNINGS 1


////拉链法
//#include<stdio.h>
//#include<stdbool.h>
//#include<string.h>
//#include<stdlib.h>
//#include<time.h>
//
//#define N 10003
//int h[N], e[N], ne[N], idx=0;
////首先，将数据映射到1-N的数组里面，如果有冲突，那么使用链表连起来，这就是拉链法
////数组模拟链表
////h[N]表示的是每一个链表的头节点的下标，N是映射过来位置
////e[N]表示的是位置N的数据
////ne[N]表示的是位置N的下一个节点的下标
//
//
//bool find(int x)
//{
//	int k = (x % N + N) % N; // 因为 x%N 有可能得到的结果是负数，这里要保证下标为正
//	for (int i = h[k];i != -1;i = ne[i])
//	{
//		if (e[i] == x)
//			return true;
//	}
//	return false;
//}
//
//void Insert(int x)
//{
//	int k = (x % N + N) % N; // 因为 x%N 有可能得到的结果是负数，这里要保证下标为正
//	e[idx] = x;    //新节点赋值
//	ne[idx] = h[k];//新节点的下一个节点指向原来的头节点
//	h[k] = idx++;  //h[k] 存储该链表的头节点位置
//	return;
//}
//
//int main()
//{
//	int tmp[10000] = { 0 };
//	srand(time(NULL));
//	memset(h, -1, sizeof(h));
//	for (int i = 0;i < 10000;i++)
//	{
//		tmp[i] = rand() % 1000000 + 9000;
//	}
//	for (int i = 0;i < 10000;i++)
//		Insert(tmp[i]);
//
//	for (int i = 0;i < 10;i++)
//	{
//		if (find(tmp[i]))
//			printf("yes!\n");
//		else
//			printf("No!\n");
//	}
//
//}



//动态分配法
//10000个数据，每个数据都在 -10^9 到 10^9 之间
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N 20003   //一般要开两倍的空间
int h[N], null = 0x3f3f3f3f;  // null表示该位置没有数据

bool find(int x)
{
	int k = (x % N + N) % N;
	while (h[k] != x && h[k] != null)  //必须满足找不到且该位置不为null，即该位置有数据但是不是x
	{
		k++;  // 找不到，那么下一个
		if (k == N) k = 0;  //如果到最后了，那么从开始找，因为不可能存在容量不够的问题
	}
	return k; // 找到了，退出循环返回位置，没找到，那么就返回应该放的位置
}


int main()
{
	memset(h, 0x3f, sizeof(h));


}