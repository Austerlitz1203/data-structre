//可以处理赋权图，但是不可以有赋权回路
//多源汇最短路，复杂度为O(N^3)

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210,INF=1e9;

int n,m,Q;//n个点，m条边，最后询问Q次

int d[N][N];


void floyd()
{
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
    //初始化
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
          {
            if(i==j) d[i][j]=0;
            else d[i][j]=INF;
          }
    }
    //给边赋初值
    while(m--)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        d[a][b]=min(w,d[a][b]);
    }

    while(Q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        if(d[a][b] > INF/2 ) puts("impossible");
        else printf("%d\n",d[a][b]);
    }


    return 0;
}
