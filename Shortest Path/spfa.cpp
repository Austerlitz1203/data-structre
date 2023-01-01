// spfa算法，和堆优化的Dijkstra算法很类似

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int dist[N];
bool st[N]; // 记录节点是否进入队列中


void add(int a, int b, int c) // 新增a到b的边，权重为c
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

// spfa 算法可以说是Bellman_Ford 算法的优化版本，但是权值不可以是负数
// 因为spfa 每一次都要遍历所有边，但是上一次操作不一定每一个边最短路都更新了，所以很多无用功
// spfa 就是用队列存储优化了的边，然后取队列里的元素进行操作，优化其相关的边
// spfa 算法一般时间复杂度是 O(m) , 最坏的情况是 O(n*m)
// 如果出题人卡在O(n*m) ，那么使用堆优化的迪杰斯特拉算法
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int>q;
    q.push(1);
    while(q.size())
    {
        int tmp=q.front();
        q.pop();

        st[tmp]=false;

        for(int i=h[tmp];i!=-1;i=ne[i])
        {
            int j=e[i];                  // j 就相当于 temp点指向的后一个点,i相当于这两个点之间的边
            if (dist[j]>dist[tmp]+w[i])  // w[] 是和边相关联的，看上面的add ，w[idx] 可以看出
            {
                dist[j]=dist[tmp]+w[i];
                if(!st[j])       // 重复进入无意义
                {
                    q.push(j);   // 压入更新后的节点
                    st[j]=true;  // 表示这个节点已经进入队列
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int ret = spfa();
    if (ret == -1 ) puts("impossible");
    else printf("%d\n", ret);

    return 0;
}