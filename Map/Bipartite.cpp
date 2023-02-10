// 二分图
// 染色法判断是否为二分图
// 染成两种颜色，每一条边的两个端点颜色不同。使用递归，深度优先遍历下去。
// 时间复杂度是O(m+n)

#include<iostream>
#include<cstring>

using namespace std;

const int N=100010,M=200010; // 无向图
int n,m;// n 代表点数，m代表边数
int h[N],e[N],ne[N],idx;

int color[N];  //每一个点是否染色

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool dfs(int u,int c)
{
    color[u]=c; // 当前节点先染色
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!color[j]) // 未染色，染成和u相异的颜色
        {
            if(!dfs(j,3-c)) return false;
        }
        else if(color[j]==c) return false; // 染色且和 u 的颜色相同，错误
    }

    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);

    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }

    // 染色法
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])  // 节点未染色，则染色
        {
            if(!dfs(i,1))  // 染色出现矛盾，不是二分图。没有矛盾就是正常递归下去染完，不进入if内部。
            {
                flag=false;
                break;
            }
        }
    }

    if(flag) puts("yes");
    else puts("no");

    return 0;
}