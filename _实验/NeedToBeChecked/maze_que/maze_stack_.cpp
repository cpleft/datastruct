#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;



/* declare */
#define M 3000
struct Node; 
struct Maze; 
struct Pos;
void MakeMaze(void);
void MazePath(Maze M, Pos start, Pos end);
Pos NextPos(Pos cur, int x);


/* structures */
struct node{
    int x, y; 
};
struct maze{
    int n, m; 
    int map[M][M];
    bool book[M][M];
};
struct pos{
    int x, y;
};


/* implementations */
void MazePath(Maze M, Pos start, Pos end){
}


Pos NextPos(Pos cur, int x){
    switch(x){
        case 0:         //east
            cur.y ++;
            return cur;
            break;
        case 1:         //sourth
            cur.x ++;
            return cur;
            break;
        case 2:         //west
            cur.y --;
            return cur;
            break;
        case 3:         //north
            cur.x --;
            return cur; 
            break;
        default:
            break;
}




void MakeMaze(void){
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


