#define _CRT_SECURE_NO_WARNINGS 1
#include"StrList.h"
void StrInit(SN S);//��ʼ��
int StrEmpty(SN* S);//���Ƿ�Ϊ��,1Ϊ�գ�0Ϊ�ǿ�
int StrCmp(SN S, SN T);


void find_next(SN* T, int* next)
{
	next[1] = 0;
	int i = 1, j = 0;
	while (i < T->size)//���ﲻ��=��һ������ڴ濴����=֮�󣬾���next[6]���ڣ���һ���棬�������++i,++jҲ֪����i
		               //�ڵ���T->size-1��ʱ��next[T->size]��ֵ�Ѿ��ҵ���
	{
		if (j == 0 || (T->data)[i-1] == (T->data)[j-1])//����-1��ԭ���ǣ���Ѱ��next[]ʱ��T�ַ���Ĭ�ϵ�һ���ַ�
			     //�±�Ϊ1����i,j���Ǻʹ�ʱ��T�ַ����ҹ�����ôע�������Ǳ�T->data[]���±��Ƕ�һ���ģ�����i��
			    //T�����ǵ�3���ַ����±꣬���ʱ��iȷȷʵʵ��=3��������T->data[]�����Ӧ���±���2�������ڱȽ�
			    //T->data[]�����ʱ�����Ҫ��������.
                 //����˵���ڱȽϵ�ǰλ��i,j���ַ���ʱ��i��jʵ�����ǳ�ǰһλ�ģ�����Ҫ-1			
			next[++i] = ++j;//�����-1����next[]��Ӱ�죬��Ϊnext[]����Ĭ�Ͼ��ǳ�ǰ1λ
		else
			j = next[j];
	}
}

int StrIndex(SN *S, SN *T,int pos)//��posλ�ÿ�ʼ��Ѱ���Ӵ�T��λ�ã�KMP�㷨��
{
	int next[10] = { 0 };
	find_next(T, next);
	int i = pos, j = 1;//��ʼֱֵ�ӳ�ǰһλ�������Ͳ�����Խ���������
	while (i <= S->size && j <= T->size)  //����"="��ԭ���ǣ�(S->data)[i - 1]�����i=S->size��ʱ��i-1����S��ַ��
	{                                     //�ַ��������һλ�����û��=����ô���Ƚϵ������ڶ����ַ�
		if (j == 0 || (S->data)[i - 1] == (T->data)[j - 1])
		{                  //j=0���������һ��ѭ��next[j]=0,ֻ��j=1�Żᷢ������(T->data)[j-1]��Ȼ�ǵ�һ���ַ�
			i++;          //���������ִ��else��˵�����ߴ�ʱ���λ�õĵ�һ���ַ��Ͳ���ȣ���ôj�͵������ڳ�ʼ������j++����=1��ʼ
			j++;
		}
		else
			j = next[j];//j=next[j],��ô�ӱ����ϣ�j��ʵ�ǳ�ǰһλ�����ԱȽϵ�ʱ��Ҫ-1
	}
	if (j > T->size)
		return i - T->size;    //����ͼ��������
	return -1;
}

void StrInsert(SN* S, int pos, SN* T);//�����Ӵ�
void StrDelete(SN* S, int pos, int len);//ɾ���Ӵ�
void StrDestory(SN* S);


