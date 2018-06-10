// by邻接表 Adj List
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define M 3000
int List[M][M];
int record[M];
int n, e;
int vis[M];

void input(){
    cin >> n >> e;
    memset(List, -1, sizeof(List));
    memset(record, 0, sizeof(record));
    for(int i = 0; i < e; i++){
        int fr, to, no;
        cin >> fr >> to >> no;
        List[fr][record[fr]] = to;
        record[fr] ++;
    }
}
void dfs(int step){
    vis[step] = 1;
    cout << step+1 <<endl;

    for(int i = 0; i < record[step]; i++)
        if(!vis[List[step][i]]){
            dfs(List[step][i]);
        }
}
int main(void){
    input();
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i);

    return 0;
}
