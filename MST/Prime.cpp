#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=510,INF=0x3f3f3f;
int n,m;
int g[N][N];
int dist[N];
bool st[N];

//这个算法就和Dijkstra算法类似，只不过把源节点换成了集合
//循环n次，找到不在集合中，且离集合最近的点（Dijkstra是离源节点）
//用这个点更新其他节点离集合的距离
int prime()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && (t==-1 || dist[j] < dist[t]))
              t=j;
        }

        if(i && dist[t]==INF) return INF;
        if(i) ret+=dist[t];  //最小生成树的所有边的长度之和，必须先加到ret，再更新
        //如果先更新，假设 t 节点有自环，那么下面更新，当k=t的时候，min(dist[t],g[t][t])。如果自环
        //为负数，那么肯定是取值自环，则结果就是错的。

        //更新，该点到原集合最短路  和  加入t点的新集合，该点到t点的最短路  之间取小的
        for(int k=1;k<=n;k++) dist[k]=min(dist[k],g[t][k]);

        st[t]=true;
    }
    return ret;
}


int main()
{
    memset(g,0x3f,sizeof g);
    scanf("%d%d",&n,&m);

    while(m--)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        g[a][b]=g[b][a]=min(g[a][b],w);
    }

    int t=prime();

    if(t==INF) puts("impossible");
    else printf("%d\n",t);

    while(1);

    return 0;
}