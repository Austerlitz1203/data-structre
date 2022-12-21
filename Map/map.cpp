#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N=10010,M=N*2;

int h[N],e[M],ne[M],idx;//数组模拟链表
int st[N];//标记该位置是否被搜索过

int Add(int a,int b) //图里面编号为a的，让其指向值为b的数据
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void dfs(int u)
{
    st[u]=true;//搜索到图中编号为u的数据了，将其置为true表示已经搜索过，避免重复搜索

    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i]; //编号i对应在图中的编号
        if(!st[j]) dfs(j);
    }
}

int main()
{
    memset(h,-1,sizeof h);

}
