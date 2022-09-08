#define _CRT_SECURE_NO_WARNINGS 1
#include"StrList.h"

int main()
{
	SN S1 = { "ababcabcacbab",13 };
	SN T1 = {"abcac",5};
	int i = StrIndex(&S1, &T1, 1);
	printf("%d", i);
}