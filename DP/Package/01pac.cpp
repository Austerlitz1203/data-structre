#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;
int n,m; // n 表示物品数量，m表示背包的容量
int v[N],w[N];  // v[i] 表示第 i 个物品的体积， w[i] 表示第i 个物品的价值
int f[N][N];    // f[n][m] 表示只拿前 n 个物品，背包容量是m 的情况下，拿到的价值最大的情况

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    // f[0][0] 到 f[0][m] 表示0件物品，背包容量 0-m 的情况，可以直接忽略
    for(int i=1;i<=n;i++)
      for(int j=0;j<=m;j++)
      {
        f[i][j]=f[i-1][j];   // 第 i 个不拿的情况，一定存在
        if(v[i] <= j) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
      }

    cout<<f[n][m]<<endl;
    return 0;
}