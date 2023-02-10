// 二分图
// 匈牙利算法求二分图的最大匹配
// 主要思想就是，左边集合的每一个点 和 右边集合的每一个点，要有一个唯一的匹配
// 现在左边点A去找右边的点B，如果B没有匹配，那么两个可以直接匹配
// 如果 B 有匹配，其匹配的是左边的点C，那么让C找下一个匹配D，找到的话，C、D匹配，然后A、B匹配
// O(mn) ,但是实际远小于它

#include<iostream>
#include<cstring>
#include<algorithm>

const int N=510,M=100010;

int n1,n2,m;  // n1 表示左边点的集合，n2表示右边点的集合，m表示边
int h[N],e[M],ne[M],idx;
int match[N]; // 全局变量，自动初始化为0
bool st[N];  // 存储 右边集合的点 是否已经被 当前左边的点 找到

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool find(int x)
{
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=true;
            if(match[j]==0 || find(match[j]))  // 右边的点目前没有匹配。或者右边点的匹配（左边的点），可以找到下一个匹配
            {
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d",&n1,&n2,&m);
    memset(h,-1,sizeof h);

    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }

    int res=0;
    for(int i=1;i<=n1;i++)
    {
        memset(st,false,sizeof st);  // 每一个左边集合的点，在找匹配的时候，都要把st置为false，因为没有找过右边的
        if(find(i)) res++;
    }

    printf("%d\n",res);

    while(1);

    return 0;
}