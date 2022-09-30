#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include"Queue.h"//要用到队列的内容

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
//前中后序遍历又被称作深度优先遍历

//层序遍历   广度优先遍历
void LeafSort(BTNode* root)
{
	assert(root);
	//创建一个队列
	Queue p;
	QueueInit(&p);
	if (root)
		QueuePush(&p, root);
	while (!QueueEmpty(&p))
	{
		BTNode* temp = QueueFront(&p);//先把第一个取出来
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

//所有节点个数，三种方法
//int LeafSize1(BTNode* root)
//{
//	static int size = 0;//全局变量
//	if (!root)
//		return;
//	if (root)
//		size++;
//	LeafSize1(root->left);
//	LeafSize1(root->right);
//}//这种方法在多线程就不合适，所以避免使用

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

//叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (!root)//空返回0
		return 0;
	if (root->left == NULL && root->right == NULL) //叶子返回1
		return 1;
	return    TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//求二叉树深度
int TreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int left=TreeDepth(root->left);
	int right=TreeDepth(root->right);

	return left > right ? left + 1 : right + 1;
}

//给一个前序读取的二叉树数据，还原二叉树
BTNode* CreatTree(char* a,int* pi)
{
	//'#'代表NULL
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
	root->left = CreatTree(a, pi);//生成左子树
	root->right = CreatTree(a, pi);//生成右子树
	
	return root;
}