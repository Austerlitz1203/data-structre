#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include"Queue.h"//要用到队列的内容

//生成一个节点
BTNode* BuyNode(BTDataType x)
{
	BTNode* temp = (BTNode*)malloc(sizeof(BTNode));
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
			QueuePush(&p, temp->left);
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
//}//这种方法在多线程就不合适，所以避免使用，并且局部静态变量，虽然生命周期是全局，但是只能够在局部修改这个变量
 //不知道什么时候置成0，而且局部静态变量，只能初始化一次

void LeafSize2(BTNode* root, int* size)
{
	if (!root)
		return;
	if (root)
		(*size)++;
	LeafSize2(root->left, size);
	LeafSize2(root->right, size);
}

int LeafSize3(BTNode* root)
{
	return root == NULL ? 0 : LeafSize3(root->left) + LeafSize3(root->right) + 1;
}

//叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (!root)//空返回0，因为如果有一个左边有子树，右边是NULL的，那么左边递归完，会开始右边，但是右边是NULL，传入NULL无法取得左右子节点
		return 0;
	if (root->left == NULL && root->right == NULL) //叶子返回1
		return 1;
	return    TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//第k层节点个数
int TreeKLevelSize(BTNode* root, int k)
{

}


//求二叉树深度
int TreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);

	return left > right ? left + 1 : right + 1;
}

//给一个前序读取的二叉树数据，还原二叉树
BTNode* CreatTree(char* a, int* pi)
{
	//'#'代表NULL
	if (a[*pi] == '#')
	{
		(*pi)++; // ++ 不可以放在判断语句里面，不然不管是不是 #  ，都要 ++
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

void ReChange(BTNode* root)
{
	if (root == NULL) return;
	else
	{
		BTNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		ReChange(root->left);
		ReChange(root->right);
	}
}

BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* ret1 = NULL, * ret2 = NULL;
	//拿值接收，不然return TreeFind(root->left, x); 太麻烦，又要递归，层次深了之后，特别麻烦
	ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;
	return NULL;
}


bool isUnivaldTree(BTNode* root)
{
	if (root == NULL)
		return true;
	if (root->left && root->data != root->left->data)
		return false;
	if (root->data && root->data != root->right->data)
		return false;
	return isUnivaldTree(root->left) && isUnivaldTree(root->right);

}

bool TreeComplete(BTNode* root)
{
	assert(root);
	//创建一个队列
	Queue p;
	QueueInit(&p);
	if (root)
		QueuePush(&p, root);
	while (!QueueEmpty(&p))
	{
		BTNode* front = QueueFront(&p);
		QueuePop(&p);
		if (front == NULL)  //出到空
			break;
		else
		{
			QueuePush(&p, front->left);
			QueuePush(&p, front->right);
		}
	}

	//出到空之后，如果后面全是空，那就是完全二叉树
	while (!QueueEmpty(&p))
	{
		BTNode* front = QueueFront(&p);
		QueuePop(&p);
		if (front != NULL)
		{
			QueueDestory(&p);
			return false;
		}
	}

	QueueDestory(&p);
	return true;

}


void TreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
	//后序来是比较好的，先销毁左右子树，再销毁自己。
	//整个递归是一层一层下去，然后从最下面free，直到根节点
}