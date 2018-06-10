#include<cstdio>
#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;

#define M 100
struct node{
    int lineNum;
    int MatchNum;
};
struct node queue[100000];
int head = 0;
int tail = 0;

char buffer[256];
char Pattern[M];                       //pattern
int next[M];                     //next array
int n, m;
int D;
void FindNext(void){
    int q = 0;
    next[0] = 0;
    next[1] = 0;
    for(int i = 2; i < m; i++){
        while(q > 0 && Pattern[q+1] != Pattern[i])
            q = next[q];
        if(Pattern[q+1] == Pattern[i])
            q += 1;
        next[i] = q;
    }
}
int KMP(void){
    D = 0;
    int q = 0;
    for(int i = 1; i < n; i++){
        if(q > 0 && Pattern[q+1] != buffer[i])
            q = next[q];
        if(Pattern[q+1] == buffer[i])
            q += 1;
        if(q == m-1){           //sucessfully matched
            //cout << i-m+2 << " ";
            if(buffer[i-m+1]<'A' || buffer[i-m+1]>'z' || (buffer[i-m+1]<'a' && buffer[i-m+1]>'Z'))
                if(buffer[i+1]<'A' || buffer[i+1]>'z' || (buffer[i+1]<'a' && buffer[i+1]>'Z')){
                D++;
                //for next match
            }
            q = 0;
        }
    }
    if(D) return 1;
    else return 0;
}

int main(void){
    cout << "Please input the word that you want to find:" <<endl;
    Pattern[0] = ' ';
    int p = 0;
    while(Pattern[p] != '\n'){
        p++;
        scanf("%c", Pattern+p);
    }
    Pattern[p] = '\0';
    m = strlen(Pattern);

    int line = 0;
    fstream in;
    in.open("Novel.txt",ios::in);
    while(!in.eof())
    {
        buffer[0] = ' ';
        buffer[1] = ' ';
        in.getline(buffer+2, 256, '\n');
        n = strlen(buffer);
        if(KMP() == 1){                 //sucessfully matched
            queue[tail].lineNum = line+1;
            queue[tail].MatchNum = D;   //from KMP()
            tail ++;
        }
        line ++;
    }
    in.close();    
    
    //output
    int sum = 0;
    for(int i = 0; i < tail; i++)
        sum += queue[i].MatchNum;
    cout << "一共出现 " << sum <<" 次"<<endl;
    for(int i = 0; i < tail; i++)
        cout<< "第 "<<queue[i].lineNum<<" 行:  "<< queue[i].MatchNum<<endl;
}
