#define _CRT_SECURE_NO_WARNINGS 1
#include"StrList.h"
void StrInit(SN S);//初始化
int StrEmpty(SN* S);//串是否为空,1为空，0为非空
int StrCmp(SN S, SN T);


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

void StrInsert(SN* S, int pos, SN* T);//插入子串
void StrDelete(SN* S, int pos, int len);//删除子串
void StrDestory(SN* S);


