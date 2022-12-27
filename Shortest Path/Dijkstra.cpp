#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=510;

int n,m;
int g[N][N]; // 邻接矩阵存储图
int dist[N]; // 代表一号点到某点的距离
bool st[N];  // 某点的最短路是否已经确定


//朴素dijkstra思想
// dist[1]=0, dist[其他] = 正无穷  ，假设集合s里面存储最短路已经确定的点
// for ( int i=0;i<n;i++) 对下面进行循环n次
// t <- 不存在于s中的，距离1最近的点
// s <- t
// 用t来更新其他点的距离

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    for (int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && (t==-1 || dist[t] > dist[j]))
              t=j;
        }

        st[t]=true;

        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }

    if(dist[n]==0x3f3f3f) return -1;

    return dist[n];
}


int main()
{
    scanf("%d%d",&n,&m); // n个点
    memset(g,0x3f,sizeof g); // 将每一个点到每一个点的距离都设置为无限大
    while(m--) // 读入m条边
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=min(g[a][b],c);
    }

    int ret=dijkstra();
    printf("%d\n",ret);
}