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

int queue[M];
int head;
int tail;

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
void bfs(int from){
    memset(queue, 0, sizeof(queue));
    head = tail = 0;
    queue[tail] = from;
    tail++;
    vis[from] = 1;
    cout << from+1 <<endl;

    while(head < tail){
        for(int i = 0; i < record[queue[head]]; i++)
            if(!vis[List[head][i]]){
                queue[tail] = List[head][i];
                cout <<List[head][i]+1 << endl;
                vis[queue[tail]] = 1;
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


/* had some bugs:
 * 
7 12
0 2 1 
2 0 1
2 1 1
2 5 1
3 1 1
3 2 1
3 4 1
4 1 1
5 3 1
6 3 1
6 4 1
6 5 1
1
3
0
2
4
5
6
7
*/
