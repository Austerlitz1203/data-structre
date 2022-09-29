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
}
int main()
{
	//test();//����ǰ�к������
	test1();//���Թ�����ȱ������ڵ�����Ҷ�ӽڵ���
	return 0;
}