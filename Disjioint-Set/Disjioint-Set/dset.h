#pragma once
#include<stdio.h>
//1-N 表示N个数据的编号
#define N 1000 

int p[N];  //p[N] 表示 节点N的前驱的编号

//查找某一编号的祖宗 + 路径压缩
int find(int x);
//合并两个集合
void jion(int x, int y);

