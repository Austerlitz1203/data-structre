#define _CRT_SECURE_NO_WARNINGS 1
#include"dset.h"

//查找某一编号的祖宗 + 路径压缩
int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

//合并两个集合
void jion(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy)             //不属于同一个集合
		p[fx] = fy; //把fx的前驱节点设置成fy
}