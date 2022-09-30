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
	//test();//测试前中后序遍历
	//test1();//测试广度优先遍历、节点数、叶子节点数、深度
	test2();//测试根据前序遍历的数据，生成二叉树
	return 0;
}

//二叉树的一些规律：
//1、满二叉树有2^h-1个节点，h为深度（从1开始）
//2、二叉树第n层，最多有2^(n-1)个节点
//3、二叉树中，度为2的节点有n2个，叶子数有n0个，那么n0=n2+1

//前序+中序可以确定一颗二叉树
// 因为前序确定根，然后中序里面根据根的位置，确定根的左子树和右子树
//二前序+后序，无法确定根的左右子树有哪些元素