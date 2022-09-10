#define _CRT_SECURE_NO_WARNINGS 1
#include"StrList.h"
void StrInit(SN* S)//初始化
{
	S->data = NULL;
	S->size = 0;
	S->capacity = 0;
}
int StrEmpty(SN* S)//串是否为空,1为空，0为非空
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
	////短的所有字符和长的均相等，长的和短的等长或者比短的长
	//if (i == len && S->size == T->size)
	//	return 0;
	//else if (i == len && S->size < T->size)
	//	return 1;
	//else
	//	return -1;

	//优化版本
	assert(S && T);
	while (*(S->data) == *(T->data)) //不等的时候才跳出
	{
		if (*S->data == '\0')//如果满足，则两个都是\0，因为只有相等才会进循环
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
	while (i < T->size)//这里不能=，一方面从内存看出，=之后，就有next[6]存在，另一方面，看下面的++i,++j也知道，i
		               //在等于T->size-1的时候，next[T->size]的值已经找到了
	{
		if (j == 0 || (T->data)[i-1] == (T->data)[j-1])//这里-1的原因是：在寻找next[]时，T字符串默认第一个字符
			     //下标为1，而i,j都是和此时的T字符串挂钩，那么注定了他们比T->data[]的下标是多一个的，比如i在
			    //T里面是第3个字符的下标，这个时候i确确实实是=3，但是在T->data[]里面对应的下标是2，所以在比较
			    //T->data[]里面的时候，务必要单独来想.
                 //就是说，在比较当前位置i,j的字符的时候，i，j实际上是超前一位的，所以要-1			
			next[++i] = ++j;//上面的-1对于next[]无影响，因为next[]本身默认就是超前1位
		else
			j = next[j];
	}
}

int StrIndex(SN *S, SN *T,int pos)//从pos位置开始，寻找子串T的位置（KMP算法）
{
	int next[10] = { 0 };
	find_next(T, next);
	int i = pos, j = 1;//初始值直接超前一位，这样就不存在越界访问问题
	while (i <= S->size && j <= T->size)  //这里"="的原因是，(S->data)[i - 1]，如果i=S->size的时候，i-1才是S地址的
	{                                     //字符串的最后一位，如果没有=，那么最多比较到倒数第二个字符
		if (j == 0 || (S->data)[i - 1] == (T->data)[j - 1])
		{                  //j=0的情况是上一次循环next[j]=0,只有j=1才会发生，而(T->data)[j-1]显然是第一个字符
			i++;          //这种情况下执行else，说明两者此时相对位置的第一个字符就不相等，那么j就得类似于初始那样，j++正好=1初始
			j++;
		}
		else
			j = next[j];//j=next[j],那么从本质上，j其实是超前一位，所以比较的时候要-1
	}
	if (j > T->size)
		return i - T->size;    //画个图就能明白
	return -1;
}

void StrInsert(SN* S, int pos, SN* T)//在第pos个字符（非下标）的位置插入子串
{
	//断言
	assert(S);
	assert(T);
	while (S->capacity - S->size < T->size)//判断空间是否够插入子串
	{
		int newcapacity1 = S->capacity == 0 ? 4 : 2 * S->capacity;
		char* ps = (char*)realloc(S->data, newcapacity1*sizeof(char));
		//由于这里是realloc，所以S必须StrInit()，不然既没有事先malloc,calloc,realloc，又没有S->data=NULL，直接崩溃了
		//可以先StrInit(S),然后StrInsert()字符串，pos=1
		//T不需要StrInit()，所以初始化的时候可以直接写其内容
		if (!ps)
		{
			printf("realloc fail!");
			exit(-1);
		}
		S->data = ps;
		S->capacity = newcapacity1;
	}

	if (!S->data)//S->data为空的时候，直接插入
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
	for (int i = tail;i >= pos - 1;i--)//S->data非空，先后移再插入
		S->data[i + T->size] = S->data[i];
	for (int i = 0;i < T->size;i++)//插入操作
		S->data[i + pos - 1] = T->data[i];
	S->size += T->size;
	S->data[S->size] = '\0';
	return;
}
void StrDelete(SN* S, int pos, int len)//删除子串
{
	//断言
	assert(S);//S为空
	assert(!StrEmpty(S));//data为空
	
	if (S->size <= len)//删除长度比当前字符串还长
		StrInit(S);

	int head = pos + len;//要移动的起始字符位置(非下标)
	int tail = S->size;//要移动的结尾字符位置(非下标)
	for (int i = head;i <= tail;i++)//前移
		S->data[i - len-1] = S->data[i-1];
	for (int i = tail - len ;i < S->size;i++)//多的变为0
		S->data[i] = '\0';
	S->size -= len;
	return;
}

void StrDestory(SN* S)
{
	S->size = 0;
	free(S->data);
	//free(S);//free()必须是之前malloc，realloc，calloc的空间，和上面realloc一样，所以这里不可以，会崩溃
}


