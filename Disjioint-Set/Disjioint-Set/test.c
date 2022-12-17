#define _CRT_SECURE_NO_WARNINGS 1
#include"dset.h"

test1()
{
	for (int i = 1;i < N;i++) p[i] = i;
	if (find(1) == find(2))
		printf("yes!\n");
	else
		printf("No!\n");

	jion(1, 2);
	if (find(1) == find(2))
		printf("yes!\n");
	else
		printf("No!\n");

	if (find(2) == find(3))
		printf("yes!\n");
	else
		printf("No!\n");

}
int main()
{
	test1();

	return 0;
}