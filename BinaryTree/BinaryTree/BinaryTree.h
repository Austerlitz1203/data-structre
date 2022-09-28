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

//����һ���ڵ�
BTNode* BuyNode(BTDataType x);
//ǰ�����
void PrevOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);