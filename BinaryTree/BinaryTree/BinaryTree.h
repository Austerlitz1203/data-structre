#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
//第k层节点个数
int TreeKLevelSize(BTNode* root, int k);
//深度
int TreeDepth(BTNode* root);
//给一个前序读取的二叉树数据，还原二叉树
BTNode* CreatTree(BTNode* root, int* pi);
//交换左右子树
void ReChange(BTNode* root);
//查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x);
//是否为unival树
bool isUnivaldTree(BTNode* root);
//是否为完全二叉树
bool TreeComplete(BTNode* root);
//销毁
void TreeDestory(BTNode* root);
