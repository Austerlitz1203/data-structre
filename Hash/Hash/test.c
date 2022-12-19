#define _CRT_SECURE_NO_WARNINGS 1


////������
//#include<stdio.h>
//#include<stdbool.h>
//#include<string.h>
//#include<stdlib.h>
//#include<time.h>
//
//#define N 10003
//int h[N], e[N], ne[N], idx=0;
////���ȣ�������ӳ�䵽1-N���������棬����г�ͻ����ôʹ�������������������������
////����ģ������
////h[N]��ʾ����ÿһ�������ͷ�ڵ���±꣬N��ӳ�����λ��
////e[N]��ʾ����λ��N������
////ne[N]��ʾ����λ��N����һ���ڵ���±�
//
//
//bool find(int x)
//{
//	int k = (x % N + N) % N; // ��Ϊ x%N �п��ܵõ��Ľ���Ǹ���������Ҫ��֤�±�Ϊ��
//	for (int i = h[k];i != -1;i = ne[i])
//	{
//		if (e[i] == x)
//			return true;
//	}
//	return false;
//}
//
//void Insert(int x)
//{
//	int k = (x % N + N) % N; // ��Ϊ x%N �п��ܵõ��Ľ���Ǹ���������Ҫ��֤�±�Ϊ��
//	e[idx] = x;    //�½ڵ㸳ֵ
//	ne[idx] = h[k];//�½ڵ����һ���ڵ�ָ��ԭ����ͷ�ڵ�
//	h[k] = idx++;  //h[k] �洢�������ͷ�ڵ�λ��
//	return;
//}
//
//int main()
//{
//	int tmp[10000] = { 0 };
//	srand(time(NULL));
//	memset(h, -1, sizeof(h));
//	for (int i = 0;i < 10000;i++)
//	{
//		tmp[i] = rand() % 1000000 + 9000;
//	}
//	for (int i = 0;i < 10000;i++)
//		Insert(tmp[i]);
//
//	for (int i = 0;i < 10;i++)
//	{
//		if (find(tmp[i]))
//			printf("yes!\n");
//		else
//			printf("No!\n");
//	}
//
//}



//��̬���䷨
//10000�����ݣ�ÿ�����ݶ��� -10^9 �� 10^9 ֮��
//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
//
//#define N 20003   //һ��Ҫ�������Ŀռ�
//int h[N], null = 0x3f3f3f3f;  // null��ʾ��λ��û������
//
//bool find(int x)
//{
//	int k = (x % N + N) % N;
//	while (h[k] != x && h[k] != null)  //���������Ҳ����Ҹ�λ�ò�Ϊnull������λ�������ݵ��ǲ���x
//	{
//		k++;  // �Ҳ�������ô��һ��
//		if (k == N) k = 0;  //���������ˣ���ô�ӿ�ʼ�ң���Ϊ�����ܴ�����������������
//	}
//	return k; // �ҵ��ˣ��˳�ѭ������λ�ã�û�ҵ�����ô�ͷ���Ӧ�÷ŵ�λ��
//}
//
//
//int main()
//{
//	memset(h, 0x3f, sizeof(h));
//
//
//}


//�ַ�����ϣ
//�����Ƚ������ַ����������ƣ��ܶ�����±�KMP��Ҫ����
#include<stdio.h>
#include<string.h>

#define N 10010
#define P 131
//��ϣһ����P���ƣ�Pһ��ȡ 131 ���� 13331
//ͬʱ����P����̫���ˣ�����Ҫmod һ����������һ���� 2^64  ,�������ֱ���� unsigned long long �����㣬
//�䱾�����8���ֽڣ�64λ������C���������ݵĴ洢���������������ݾ� �൱��mod 2^64

typedef unsigned long long ULL;
char str[N];
ULL h[N], p[N];
//str[N] �洢�ַ���
//h[N]��ʾ�ַ���������ǰ׺�Ĺ�ϣֵ
//p[N]��ʾP��i�η�

int gets(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	int m, n;  // �ַ�����m�����֣�����n��
	scanf("%d%d%s", &m, &n, str + 1);
	//��str+1 ��ʼ�����ַ�����strλ�õ���0������һ���棬h[0]=0�����������ѭ�������ʼ����
	//��һ����ҲӦ��  �����Ҫ�����ַ����������±�����ʾ������"abcdef"  ��ô h[1]="a",h[2]="ab"��
	p[0] = 1;
	for (int i = 1;i < N;i++)
	{
		h[i] = h[i - 1] * P + str[i]; //ÿһ���ַ���ascll��ֵ����ʾ���Ӧ������
		p[i] = p[i - 1] * P;  //p[i]����P��i�η�
	}

	while (n--)
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (gets(l1, r1) == gets(l2, r2))
		{
			printf("Yes!\n");
		}
		else
			printf("No!\n");
	}
}




