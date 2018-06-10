#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

#define M 1000
typedef struct{
    int x;
    int y;
}PosType;
typedef struct {
    int ord;
    PosType seat;
    int di;
}SElemType;
typedef struct{
    int n, m;
    int map[M][M];
}MazeType;

stack<SElemType> s;
PosType start;
PosType end;
MazeType maze;

void makemaze(void);
bool mazepath(void);
void footprint(PosType p);
void markprint(PosType p);
PosType nextpos(PosType p, int t);
bool pass(PosType p);


PosType nextpos(PosType p, int t){
    switch(t){
        case 1: 
            p.y += 1; return p;
        case 2:
            p.x += 1; return p;
        case 3:
            p.y -= 1; return p;
        case 4:
            p.x -= 1; return p;
        default: return p;
    }
}

bool pass(PosType p){
    if(maze.map[p.x][p.y] == 0) return 1;
    else return 0;
}

void footprint(PosType p){
    maze.map[p.x][p.y] = 1;
}

void markprint(PosType p){
    maze.map[p.x][p.y] = 1;
}

void makemaze(void){
    cout << "Start:" <<endl;
    cin >> start.x >> start.y;
    cout << "End:" << endl;
    cin >> end.x >> end.y;
    cout << "map's n & m:" <<endl;
    cin >> maze.n >> maze.m;
    cout << "map:" <<endl;
    for(int i = 1; i <= maze.n; i++)
        for(int j = 1; j <= maze.m; j++){
            int x;
            cin >> x;
            maze.map[i][j] = x;
        }
    //Init
    for(int i = 0; i <= maze.n+1; i++){
        maze.map[i][0] = 1;
        maze.map[i][maze.m+1] = 1;
    }
    for(int i = 0; i <= maze.m+1; i++){
        maze.map[0][i] = 1;
        maze.map[maze.n+1][i] = 1;
    }
}
    
bool mazepath(void){
    PosType curpos;
    int curstep;
    curpos = start;
    curstep = 1;
    SElemType e;
    e.ord = curstep;
    e.seat = curpos;
    e.di = 1;
    do{
        if(pass(curpos)){
            //footprint(curpos);
            s.push(e);
            if(curpos.x == end.x && curpos.y == end.y) return true;

            curpos = nextpos(curpos, 1);
            curstep++;
        }
        else{
            if(!s.empty()){
                s.pop();
                while(e.di == 4 && !s.empty()){
                    markprint(e.seat);
                    s.pop();
                }
                if(e.di < 4){
                    e.di ++;
                    s.push(e);
                    curpos = nextpos(e.seat, e.di);
                }
            }
        }

    }while(!s.empty());
    //failed to find the way 
    return false;
}


int main(void){
    makemaze();
    if(mazepath())
        while(!s.empty()){
            cout << s.top().ord <<" "<< s.top().seat.x <<" "<< s.top().seat.y <<" "<< s.top().di <<endl;
            s.pop();
        }
    else cout << "Failed to find the way!" <<endl;

    return 0;
}
/*
    int ord;
    PosType seat;
    int di;
*/
