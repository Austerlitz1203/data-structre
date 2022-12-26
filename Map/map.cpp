#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 10010, M = N * 2;

int h[N], e[M], ne[M], idx; // 数组模拟链表
int st[N];                  // 标记该位置是否被搜索过

int Add(int a, int b) // 图里面值为a的，让其指向值为b的数据
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u)
{
    st[u] = true; // 搜索到图中值为u的数据了，将其置为true表示已经搜索过，避免重复搜索

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i]; // 编号i对应在图中的编号
        if (!st[j])
            dfs(j);
    }
}

// 宽搜,要求返回第N个节点到根节点的距离
int d[N], q[N]; // 图中有N个数据，d[]表示的是从根节点到某点的路径长度，q[] 表示的是队列

int bfs()
{
    int hh = 0, tt = 0; // 队头和队尾
    memset(d, -1, sizeof d);
    q[0] = 1;
    d[1] = 0; // 根节点到根节点自然为0
    while (hh < tt)
    {
        int tmp = q[hh++]; // 取数据并出队
        for (int i = h[tmp]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1) // 未搜索过,避免自环和重边
            {
                d[j] = d[tmp] + 1;
            }
        }
    }
    return d[N];
}

// 判断是否存在 有向图的拓扑序列,此时d[] 代表的是某个点的入度，这里add边之后，是要d[b]++的，代表多了一个入度
bool topsort()
{
    int hh = 0, tt = 0;
    for (int i = 0; i < N; i++)
    {
        if (!d[i])
            q[++tt] = i;
    }

    while (hh <= tt)
    {
        int tmp = q[hh++];
        for (int i = h[tmp]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (!d[j])
                q[++tt] = j;
        }
    }
    return tt == N - 1;
}

int main()
{
    memset(h, -1, sizeof h);

    // 拓扑测试
    int m;
    cin >> m;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Add(a, b);
        d[b]++;
    }
}
