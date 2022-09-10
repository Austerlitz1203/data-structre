#define _CRT_SECURE_NO_WARNINGS 1
#include"StrList.h"
void StrInit(SN* S)//��ʼ��
{
	S->data = NULL;
	S->size = 0;
	S->capacity = 0;
}
int StrEmpty(SN* S)//���Ƿ�Ϊ��,1Ϊ�գ�0Ϊ�ǿ�
{
	if (S->data == NULL)
		return 1;
	else
		return 0;
}
int StrCmp(SN* S, SN* T)
{
	//int len = S->size < T->size ? S->size : T->size;
	//int i = 0;
	//for (i = 0;i < len;i++)
	//{
	//	if (S->data[i] == T->data[i])
	//		continue;
	//	else if (S->data[i] < T->data[i])
	//		return 1;
	//	else
	//		return -1;
	//}
	////�̵������ַ��ͳ��ľ���ȣ����ĺͶ̵ĵȳ����߱ȶ̵ĳ�
	//if (i == len && S->size == T->size)
	//	return 0;
	//else if (i == len && S->size < T->size)
	//	return 1;
	//else
	//	return -1;

	//�Ż��汾
	assert(S && T);
	while (*(S->data) == *(T->data)) //���ȵ�ʱ�������
	{
		if (*S->data == '\0')//������㣬����������\0����Ϊֻ����ȲŻ��ѭ��
			return 0;
		S->data++;
		T->data++;
	}
	return *(S->data) - *(T->data);  

}


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

void StrInsert(SN* S, int pos, SN* T)//�ڵ�pos���ַ������±꣩��λ�ò����Ӵ�
{
	//����
	assert(S);
	assert(T);
	while (S->capacity - S->size < T->size)//�жϿռ��Ƿ񹻲����Ӵ�
	{
		int newcapacity1 = S->capacity == 0 ? 4 : 2 * S->capacity;
		char* ps = (char*)realloc(S->data, newcapacity1*sizeof(char));
		//����������realloc������S����StrInit()����Ȼ��û������malloc,calloc,realloc����û��S->data=NULL��ֱ�ӱ�����
		//������StrInit(S),Ȼ��StrInsert()�ַ�����pos=1
		//T����ҪStrInit()�����Գ�ʼ����ʱ�����ֱ��д������
		if (!ps)
		{
			printf("realloc fail!");
			exit(-1);
		}
		S->data = ps;
		S->capacity = newcapacity1;
	}

	if (!S->data)//S->dataΪ�յ�ʱ��ֱ�Ӳ���
	{
		S->data = (char*)malloc((T->size+1)*sizeof(char));
		for (int i = 0;i < T->size;i++)
		{
			S->data[i] = T->data[i];
		}
		S->size = T->size;
		S->data[S->size] = '\0';
		return;
	}

	int tail = S->size - 1;
	for (int i = tail;i >= pos - 1;i--)//S->data�ǿգ��Ⱥ����ٲ���
		S->data[i + T->size] = S->data[i];
	for (int i = 0;i < T->size;i++)//�������
		S->data[i + pos - 1] = T->data[i];
	S->size += T->size;
	S->data[S->size] = '\0';
	return;
}
void StrDelete(SN* S, int pos, int len)//ɾ���Ӵ�
{
	//����
	assert(S);//SΪ��
	assert(!StrEmpty(S));//dataΪ��
	
	if (S->size <= len)//ɾ�����ȱȵ�ǰ�ַ�������
		StrInit(S);

	int head = pos + len;//Ҫ�ƶ�����ʼ�ַ�λ��(���±�)
	int tail = S->size;//Ҫ�ƶ��Ľ�β�ַ�λ��(���±�)
	for (int i = head;i <= tail;i++)//ǰ��
		S->data[i - len-1] = S->data[i-1];
	for (int i = tail - len ;i < S->size;i++)//��ı�Ϊ0
		S->data[i] = '\0';
	S->size -= len;
	return;
}

void StrDestory(SN* S)
{
	S->size = 0;
	free(S->data);
	//free(S);//free()������֮ǰmalloc��realloc��calloc�Ŀռ䣬������reallocһ�����������ﲻ���ԣ������
}


