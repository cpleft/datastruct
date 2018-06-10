#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 99999
//#define max 999
using namespace std;

int n,m,a[1005][1005],vis[1005],cost[1005];

int prim()
{
    int ans = 0;
    vis[1] = 1;
    for(int i = 1;i <= n;i++)   cost[i] = a[1][i];
    for(int i = 2;i <= n;i++)//大循环是没有加入生成树的结点数
    {
        int minn = INF,pos = -1;
        for(int j = 1;j <= n;j++)//选择权值最小的边的尾结点
        {
            if(!vis[j] && cost[j] < minn)
            {
                minn = cost[j];
                pos = j;
            }
        }
        if(pos == -1)   return -1;//没选择上

        cout << pos <<endl;
        for(int k = 1; k <= n; k++)
            cout << a[pos][k] << " ";
        cout << endl;

        ans += minn; //总路径长度
        vis[pos] = 1;//被选择结点入最小生成树
        for(int j = 1;j <= n;j++)
        {
            if(a[pos][j] < cost[j]) 
                cost[j] = a[pos][j];//更新各边权值为较小权值
        }
    }
    return ans;
}
int main()
{
    //memset(a, 1000,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            a[i][j]=INF;

    for(int i = 1;i <= m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y] = a[y][x] = z;
    }
    
    
    int ans = prim();
    if(ans == -1)   printf("?\n");
    else    printf("%d\n",ans);
    return 0;

}
