//堆优化版的Dijkstra

#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

const int N=100010;
int h[N],e[N],ne[N],w[N],idx;
int n,m;
int dist[N];
bool st[N];
typedef pair<int,int>PII; // 第一个元素存储最短路长度，第二个点数存储图里面的编号

void add(int a,int b,int c) // 新增a到b的边，权重为c
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

//堆优化的Dijkstra，主要就是用堆存储，这样子每次拿出最小值的时候，时间复杂度就是1，不是n，然后遍历n次，最后时间复杂度是n^2 了
//适用于稀疏图
int Dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1}); // 第一个点到第一个点的距离是0

    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();

        int ver=t.second,distance=t.first;
        if (st[ver]) continue; // st[ver] 为true，说明算过了最短路，进行下一次
        st[ver]=true;

        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j] > distance+w[i])
            {
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }

    if(dist[n] == 0x3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int ret=Dijkstra();
    printf("%d\n",ret);

    return 0;
}