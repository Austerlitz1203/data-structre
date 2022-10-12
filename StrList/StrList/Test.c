#define _CRT_SECURE_NO_WARNINGS 1
#include"StrList.h"

void Test1()
{
	SN S1 = { "ababcabcacbab",13,16 };
	SN T1 = { "abcac",5,8 };
	int i = StrIndex(&S1, &T1, 1);
	printf("%d\n", i);
}
void Test2()
{
	SN S1;
	SN S2 = { "ababcabcacbab",13,16 };
	StrInit(&S1);
	SN T1 = { "abcac",5,8 };
	StrInsert(&S1, 1, &S2);//由于是realloc，所以S1必须StrInit()之后再插入想要的内容
	//printf("%s\n", S1.data);

	StrInsert(&S1, 2, &T1);
	//StrDestory(&S1);
	printf("%s\n", S1.data);
}

void Test3()
{
	//SN S1 = { "ababcabcacbab",13,16 };// "ababcabcacbab"是字符串常量，无法更改，所以必须要把它Insert一下，成栈区的
	//char c = S1.data[0];
	//printf("%c", c);
	//从这里看出是可以访问字符串,但是无法修改

	SN S1;
	SN S2 = { "ababcabcacbab",13,16 };
	StrInit(&S1);
	StrInsert(&S1, 1, &S2);//Insert之后，S1.data空间是堆区的,必须要换成栈区的才可以修改，不然字符串常量不可改

	StrDelete(&S1, 1, 4);
	printf("%s", S1.data);
}

void Test4()
{
	SN a = { "aaacdef",7,10 };
	SN b = { "aaacdeghij",10,10 };
	printf("%d ", StrCmp(&a, &b));
}

int main()
{
	//验证KMP算法
	//Test1();

	//验证插入子串
	Test2();

	//验证删除子串
	//Test3();

	//验证StrLen
	//Test4();
}