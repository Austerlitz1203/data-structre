#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=510,M=10010;  // 点数500，边数10000

//有 n 个点，m条边，求出从1号点到n号点的最多经过k条边的最短距离
int m,n,k; // m条边，n个点，

int dist[N],backup[N]; // dist[N] 标识每个点的最短路长度；backup表示每一次计算某个点的最短路，上一次的数据

struct Edge
{
    int a,b,w;  // a点到b点的边，其权值是w
}edges[M];

// 该算法可以用于边的权值为负的情况，迪杰斯特拉算法就不可以
// for n 次
// for 所有的边（a，b，w）
//    dist[b]=min(dist[b],dist[a]+w);   其中 dist[a] 一定是上一次得到的结果
//  O(n*m)
int bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++)
        {
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    // 因为此算法支持边的权值为负数，而根据上面判断的条件， 0x3f3f3f 减去某个值可能是dist[N] 的结果
    // 所以如果直接判断 dist[n] == 0x3f3f3f ，就不可以，实际上可能还是无穷
    if(dist[n] > 0x3f3f3f/2 ) return -1;

    return dist[n];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",a,b,w);
        edges[i]={a,b,w};
    }
    int t=bellman_ford();
    if (t==-1) puts("impossible");
    else printf("%d\n",t);
    return 0;
}