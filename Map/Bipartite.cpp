// 二分图
// 1.染色法

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
        if(!color[j])
        {
            if(!dfs(j,3-c)) return false;
        }
        else if(color[j]==c) return false;
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
        if(!color[i])
        {
            if(!dfs(i,1))
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