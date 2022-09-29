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
	printf("前序： ");
	PrevOrder(a);
	printf("\n中序： ");
	InOrder(a);
	printf("\n后序： ");
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
	//test();//测试前中后序遍历
	test1();//测试广度优先遍历、节点数、叶子节点数
	return 0;
}