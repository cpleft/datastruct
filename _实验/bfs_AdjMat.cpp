// by邻接矩阵 Adj Matrix
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define M 3000
int martix[M][M];
int n, e;
int vis[M];

int queue[M];
int head;
int tail;

void input(){
    cin >> n >> e;
    memset(martix, 0, sizeof(martix));
    for(int i = 0; i < e; i++){
        int fr, to, no;
        cin >> fr >> to >> no;
        martix[fr][to] = no;
    }
}
void bfs(int from){
    memset(queue, 0, sizeof(queue));
    head = tail = 0;
    queue[tail] = from;
    tail++;
    vis[from] = 1;
    cout << from+1 <<endl;

    while(head < tail){
        for(int i = 0; i < n; i++)
            if(martix[head][i] != 0 && !vis[i]){
                queue[tail] = i;
                cout << i+1 << endl;
                vis[i] = 1;
                tail++;
            }
        head++;
    }
}
int main(void){
    input();
    for(int i = 0; i < n; i++)
        if(!vis[i])
            bfs(i);

    return 0;
}
