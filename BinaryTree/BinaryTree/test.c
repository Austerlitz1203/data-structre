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
}
int main()
{
	test();
	return 0;
}