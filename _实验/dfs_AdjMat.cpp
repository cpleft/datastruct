// by邻接矩阵 Adj Matrix
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define M 3000
int martix[M][M];
int n, e;
int vis[M];

void input(){
    cin >> n >> e;
    memset(martix, 0, sizeof(martix));
    for(int i = 0; i < e; i++){
        int fr, to, no;
        cin >> fr >> to >> no;
        martix[fr][to] = no;
    }
}
void dfs(int step){
    vis[step] = 1;
    cout << step+1 <<endl;

    for(int i = 0; i < n; i++)
        if(martix[step][i] != 0 && !vis[i]){
            dfs(i);
        }
}
int main(void){
    input();
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i);

    return 0;
}
