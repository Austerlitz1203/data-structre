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