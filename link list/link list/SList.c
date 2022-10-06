#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListPrint(SLTNode* phead)
{
	//����,������ֱ�ӱ���
	assert(phead != NULL);
	SLTNode* temp = phead;
	while (temp != NULL)
	{
		printf("%d->", (*temp).data);
		temp = (*temp).next;
	}
	printf("\n");

}

SLTNode* SListBuySLTNode(SLTDataType x)
{
	SLTNode* temp = (SLTNode*)malloc(sizeof(SLTNode));
	if (temp == NULL)
	{
		printf("malloc error!");
		exit(-1);
	}
	//������洢��ӵ����ݣ�ָ����Ϊ��
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void SListPushFront(SLTNode** phead, SLTDataType x)
{
	assert(phead);
	SLTNode* newnode= SListBuySLTNode(x);
	newnode->next = *phead;
	*phead = newnode;
}

void SListPushBack(SLTNode** phead, SLTDataType x)
{
	//����
	assert(phead);
	SLTNode* newnode = SListBuySLTNode(x);
	SLTNode* temp = *phead;
	//û�����ݵ������
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	//�����ݵ������
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void SListPopFront(SLTNode** phead)
{
	assert(*phead != NULL);

	SLTNode* temp = *phead;
	*phead = temp->next;
	free(temp);
	temp = NULL;
}

void SListPopBack(SLTNode** phead)
{
	//����
	assert(*phead != NULL);
	SLTNode* temp = *phead;
	//ֻ��һ�����ݵ�����£�free*phead��*pheadҪ�óɿ�
	if (temp->next == NULL)
	{
		free(temp);
		*phead = NULL;
	}
	//��������£��µ������һ�����ݵ�ָ����ҪΪ��
	else
	{
		SLTNode* prev = NULL;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		free(temp);
		prev->next = NULL;
	}
}

//��ѯ����
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	//����
	assert(phead != NULL);

	SLTNode* temp = phead;
	while(temp != NULL)
	{
		if (temp->data == x)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}
//��posλ��֮ǰ��������
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x)
{
	//���ԣ������������Ϊ�ٵ�ʱ�򱨴�phead==NULL����
	assert(phead);

	SLTNode* newnode = SListBuySLTNode(x);
	//pos��ͷ�ڵ�����
	if (*phead == pos)
	{
		newnode->next = *phead;
		*phead = newnode;
	}
	else
	{
		SLTNode* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next=newnode;
	}

}
//���м�ɾ������
void SListErase(SLTNode** phead, SLTNode* pos)
{
	//����������
	assert(*phead);
	//ɾ��ͷ�ڵ�
	if (pos == *phead)
	{
		*phead =pos->next;
	}
	else
	{
		SLTNode* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
	}
	free(pos);
}
void SListDestory(SLTNode** phead)
{
	//���ԣ���������Ҫ����
	assert(*phead);

	SLTNode* temp = *phead;
	SLTNode* cur = *phead;
	while (temp!=NULL)
	{
		cur = temp->next;
		free(temp);
		temp = cur;
	}
	*phead = NULL;
}

//�鲢
void merge(SLTNode* a, SLTNode* b, SLTNode** ret)
{
	SLTNode* temp1 = a;
	SLTNode* temp2 = b;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->data < temp2->data)
		{
			SListPushBack(ret, temp1->data);
			temp1 = temp1->next;
		}
		else
		{
			SListPushBack(ret, temp2->data);
			temp2 = temp2->next;
		}
	}
	if (temp1)//temp2�鲢����
	{
		while (temp1)
		{
			SListPushBack(ret, temp1->data);
			temp1 = temp1->next;
		}
	}
	else//temp1�鲢����
	{
		while (temp2)
		{
			SListPushBack(ret, temp2->data);
			temp2 = temp2->next;
		}
	}
	return;
}

//�����ֿ���������ǰ�棬�����ں��棬���λ�ò���
void test2(SLTNode** a)
{
	//��������
	int x = 0;
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &x);
		SListPushBack(a, x);
	}
	//������arr�洢����
	int count = 0;
	SLTDataType arr[N] = { 0 };
	SLTNode* temp = *a;
	while (temp)
	{
		if (temp->data < 0)
			arr[count++] = temp->data;
		temp = temp->next;
	}
	temp = *a;
	while (temp)
	{
		if (temp->data > 0)
			arr[count++] = temp->data;
		temp = temp->next;
	}
	//���¸�ֵ
	count = 0;
	temp = *a;
	while (temp)
	{
		temp->data = arr[count++];
		temp = temp->next;
	}
	return;
}
