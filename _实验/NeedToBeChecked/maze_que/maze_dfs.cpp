// 迷宫问题
// dfs


#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

void makemaze(void);
void dfs(int x, int y, int step);                                     //

#define M 1000
int map[M][M];
bool book[M][M];
int n, m;
int sx, sy, fx, fy;
int next[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};//down, right, up, left
struct path{
    int x;
    int y;
};
path p[M];
int flag = 0;

void dfs(int x, int y, int step){
    if(flag == 1) return;
    if(x == fx && y == fy){
        printf("find it!");
        for(int i = 1; i < step; i++)
            cout << p[i].x << " " << p[i].y << endl;
        flag = 1;
    }
    else for(int i = 0; i < 4; i++){
        int tx = x + next[i][0];
        int ty = y + next[i][1];
        if(map[tx][ty] == 0 && book[tx][ty] == 0){
            book[tx][ty] = 1;
            p[step].x = tx;
            p[step].y = ty;
            dfs(tx, ty, step+1);
            book[tx][ty] = 0;
        }
    }

}

int main(void){
    makemaze();
    dfs(sx, sy, 1);

    return 0;
}


void makemaze(void){
    cout << "Size of the maze:(n*m) Less than 999" << endl;
    cout << "n: " <<endl;
    cin >> n;
    cout << "m: " <<endl;
    cin >> m;
    cout << "Start Position:" << endl;
    cout << "x:" <<endl;
    cin >> sx;
    cout << "y:" <<endl;
    cin >> sy;
    cout << "Finish Position:" << endl;
    cout << "x:" <<endl;
    cin >> fx;
    cout << "y:" <<endl;
    cin >> fy;

    //Init the maze
    for(int i = 0; i <= n+1; i++){
        map[i][0] = 1;
        map[i][m+1] = 1;
    }
    for(int i = 0; i <= m+1; i++){
        map[0][i] = 1;
        map[n+1][i] = 1;
    }

    //input
    cout << "input your maze" <<endl;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int o;
            cin >> o;
            map[i][j] = o;
        }
}


