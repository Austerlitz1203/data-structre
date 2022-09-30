#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

//生成一个节点
BTNode* BuyNode(BTDataType x);
//前序遍历
void PrevOrder(BTNode* root);
//中序遍历
void InOrder(BTNode* root);
//后序遍历
void PostOrder(BTNode* root);
//层序遍历
void LeafSort(BTNode*);
//总结点个数，三种方法
int LeafSize1(BTNode* root);

void LeafSize2(BTNode* root, int* size);

int LeafSize3(BTNode* root);
//叶子节点个数
int TreeLeafSize(BTNode* root);
//深度
int TreeDepth(BTNode* root);
//给一个前序读取的二叉树数据，还原二叉树
BTNode* CreatTree(BTNode* root, int* pi);
