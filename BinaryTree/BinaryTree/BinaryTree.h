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

//����һ���ڵ�
BTNode* BuyNode(BTDataType x);
//ǰ�����
void PrevOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);
//�������
void LeafSort(BTNode*);
//�ܽ����������ַ���
int LeafSize1(BTNode* root);

void LeafSize2(BTNode* root, int* size);

int LeafSize3(BTNode* root);
//Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root);
//��k��ڵ����
int TreeKLevelSize(BTNode* root, int k);
//���
int TreeDepth(BTNode* root);
//��һ��ǰ���ȡ�Ķ��������ݣ���ԭ������
BTNode* CreatTree(BTNode* root, int* pi);
//������������
void ReChange(BTNode* root);
//����ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x);
//�Ƿ�Ϊunival��
bool isUnivaldTree(BTNode* root);
//�Ƿ�Ϊ��ȫ������
bool TreeComplete(BTNode* root);
//����
void TreeDestory(BTNode* root);
