#define _CRT_SECURE_NO_WARNINGS 1
#include"dset.h"

//����ĳһ��ŵ����� + ·��ѹ��
int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

//�ϲ���������
void jion(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy)             //������ͬһ������
		p[fx] = fy; //��fx��ǰ���ڵ����ó�fy
}