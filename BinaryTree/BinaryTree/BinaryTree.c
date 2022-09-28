#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//生成一个节点
BTNode* BuyNode(BTDataType x)
{
	BTNode* temp=(BTNode*)malloc(sizeof(BTNode));
	if (temp == NULL)
	{
		exit(-1);
		return;
	}
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//前序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
	
}
//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}