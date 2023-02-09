// 稠密图用 Kruskal 算法即可，堆优化的 Prime算法过于麻烦
// 1. 所有边从小到大排序  O(m*logm)
// 2. 枚举每一条边 ab，以及它的权重 c    三行总共 O(n)
//      if  ab 不连通
//            将这条边加入集合中

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;

int n,m;
int p[N]; // 并查集

struct Edge
{
    int a,b,w;

    bool operator<(const Edge& m)const
    {
        return w<m.w;
    }

}edges[N];

int find(int x) // 并查集，找到祖先节点
{
    if(p[x] != x) p[x]=find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d",&n,&m); // n 表示多少个点，m表示多少条边

    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }

    // Kruskal 算法
    sort(edges,edges+m);
    for(int i=1;i<=n;i++) p[i]=i;  // 初始化每个节点的父亲节点

    int res=0,cnt=0; // res 记录最小生成树的总权重， cnt 记录最小生成树有多少条边
    for(int i=0;i<m;i++)
    {
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        a=find(a),b=find(b);
        if(a != b)  // a，b不在一个集合中
        {
            p[a]=b;
            res+=w;
            cnt++;
        }
    }

    // n个节点，并且是最小生成树， n-1 条边
    if(cnt < n-1) puts("impossible!");
    else cout<<res<<endl;

    return 0;
}