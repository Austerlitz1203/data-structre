#pragma once
#include"BinaryTree.h"
test()
{
	BTNode* a = BuyNode('A');
	BTNode* b = BuyNode('B');
	BTNode* c = BuyNode('C');
	BTNode* d = BuyNode('D');
	BTNode* e = BuyNode('E');
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	printf("ǰ�� ");
	PrevOrder(a);
	printf("\n���� ");
	InOrder(a);
	printf("\n���� ");
	PostOrder(a);
	printf("\n");
	LeafSort(a);
	printf("\n");
	printf("%d ", TreeLeafSize(a));
}

test1()
{
	BTNode* a = BuyNode('A');
	BTNode* b = BuyNode('B');
	BTNode* c = BuyNode('C');
	BTNode* d = BuyNode('D');
	BTNode* e = BuyNode('E');
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	LeafSort(a);
	printf("\n");
	int count = 0;
	LeafSize2(a,&count);
	printf("%d ", count);
	printf("\n");
	printf("%d ", LeafSize3(a));
	printf("\n");
	printf("%d ", TreeLeafSize(a));
	printf("\n");
	printf("%d ", TreeDepth(a));
}
test2()
{
	char a[]="abc##de#g##f###";
	int i = 0;
	BTNode* temp = CreatTree(a, &i);
	PrevOrder(temp);
}
int main()
{
	//test();//����ǰ�к������
	//test1();//���Թ�����ȱ������ڵ�����Ҷ�ӽڵ��������
	test2();//���Ը���ǰ����������ݣ����ɶ�����
	return 0;
}

//��������һЩ���ɣ�
//1������������2^h-1���ڵ㣬hΪ��ȣ���1��ʼ��
//2����������n�㣬�����2^(n-1)���ڵ�
//3���������У���Ϊ2�Ľڵ���n2����Ҷ������n0������ôn0=n2+1

//ǰ��+�������ȷ��һ�Ŷ�����
// ��Ϊǰ��ȷ������Ȼ������������ݸ���λ�ã�ȷ��������������������
//��ǰ��+�����޷�ȷ������������������ЩԪ��