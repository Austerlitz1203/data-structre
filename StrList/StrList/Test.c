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
	StrInsert(&S1, 1, &S2);//������realloc������S1����StrInit()֮���ٲ�����Ҫ������
	//printf("%s\n", S1.data);

	StrInsert(&S1, 2, &T1);
	//StrDestory(&S1);
	printf("%s\n", S1.data);
}

void Test3()
{
	//SN S1 = { "ababcabcacbab",13,16 };// "ababcabcacbab"���ַ����������޷����ģ����Ա���Ҫ����Insertһ�£���ջ����
	//char c = S1.data[0];
	//printf("%c", c);
	//�����￴���ǿ��Է����ַ���,�����޷��޸�

	SN S1;
	SN S2 = { "ababcabcacbab",13,16 };
	StrInit(&S1);
	StrInsert(&S1, 1, &S2);//Insert֮��S1.data�ռ��Ƕ�����,����Ҫ����ջ���Ĳſ����޸ģ���Ȼ�ַ����������ɸ�

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
	//��֤KMP�㷨
	//Test1();

	//��֤�����Ӵ�
	Test2();

	//��֤ɾ���Ӵ�
	//Test3();

	//��֤StrLen
	//Test4();
}