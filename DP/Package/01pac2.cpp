// 01背包 优化成一维数组
// 原理：   f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i])
// 1. 计算 f[i] 只用到了 f[i-1]行 ，可以用滚动数组。
// 2. 对于 j 和 j-v[i] 都是 <= j 的，没有在 j 的两侧。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];


int main()
{
    cin >> n >>m;

    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++)
      for(int j=m;j>=v[i];j--)
        f[j]=max(f[j],f[j-v[i]]+w[i]);

    cout << f[m] <<endl;

    return 0;
}