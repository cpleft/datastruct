// 迷宫问题


#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

void makemaze(void);

#define M 1000;
int map[M][M];
bool book[M][M];
int n, m;
int sx, sy, fx, fy;
int next[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};//down, right, up, left
struct node{
    int x, y, d;
}

int main(void){
    makemaze();
    stack<node> S;

    int x = sx, y = sy;

    do{
        if(map[x+nx][y+ny] == 0 && book[x+nx][y+ny] == 0){
            book[x+nx][y+ny] = 1;
            S.push(x+nx, y+ny)

        }
        


    }while(!s.empty());

    //failed to find the outway:
    cout << "Failed to find the outway!" <<endl;
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


