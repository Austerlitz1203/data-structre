#include<iostream>
using namespace std;

const int N=20;
int n;
char g[N][N];
bool col[N],dg[N],udg[N];//分别代表该列，/ 和 \ 斜线方向上面的

void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++) puts(g[i]);
        puts("");
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!col[i] && !dg[u+i] && !udg[n-u+i]) //y=x+b,则b=y-x，对应就是 b=
        {
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            g[u][i]='.';
            col[i] = dg[u + i] = udg[n - u + i] = false;
        }
    }

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          g[i][j]='.';
    dfs(0);
    while(1);
    return 0;
}