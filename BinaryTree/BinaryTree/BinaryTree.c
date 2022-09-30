#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include"Queue.h"//Ҫ�õ����е�����

//����һ���ڵ�
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

//ǰ�����
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
//�������
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
//�������
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
//ǰ�к�������ֱ�����������ȱ���

//�������   ������ȱ���
void LeafSort(BTNode* root)
{
	assert(root);
	//����һ������
	Queue p;
	QueueInit(&p);
	if (root)
		QueuePush(&p, root);
	while (!QueueEmpty(&p))
	{
		BTNode* temp = QueueFront(&p);//�Ȱѵ�һ��ȡ����
		QueuePop(&p);
		printf("%c ", temp->data);
		if (temp->left)
		{
			QueuePush(&p,temp->left);
		}
		if (temp->right)
		{
			QueuePush(&p, temp->right);
		}
	}
	return;
}

//���нڵ���������ַ���
//int LeafSize1(BTNode* root)
//{
//	static int size = 0;//ȫ�ֱ���
//	if (!root)
//		return;
//	if (root)
//		size++;
//	LeafSize1(root->left);
//	LeafSize1(root->right);
//}//���ַ����ڶ��߳̾Ͳ����ʣ����Ա���ʹ��

void LeafSize2(BTNode* root,int *size)
{
	if (!root)
		return;
	if (root)
		(*size)++;
	LeafSize2(root->left,size);
	LeafSize2(root->right,size);
}

int LeafSize3(BTNode* root)
{
	return root == NULL ? 0 : LeafSize3(root->left) + LeafSize3(root->right) + 1;
}

//Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	if (!root)//�շ���0
		return 0;
	if (root->left == NULL && root->right == NULL) //Ҷ�ӷ���1
		return 1;
	return    TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//����������
int TreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int left=TreeDepth(root->left);
	int right=TreeDepth(root->right);

	return left > right ? left + 1 : right + 1;
}

//��һ��ǰ���ȡ�Ķ��������ݣ���ԭ������
BTNode* CreatTree(char* a,int* pi)
{
	//'#'����NULL
	if (a[*pi]=='#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		exit(-1);
		return;
	}
	root->data = a[*pi];
	++(*pi);
	root->left = CreatTree(a, pi);//����������
	root->right = CreatTree(a, pi);//����������
	
	return root;
}