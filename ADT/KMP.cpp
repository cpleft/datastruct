/*
 * KMP
 *
 *
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define M 1000
char T[M];              //Text string
char P[M];              //Pattern string
int next[M];
int n, m;

void FindNext(void){
    next[0] = 0;        //from 1 on
    next[1] = 0;        //init
    int q = 0;
    for(int i = 2; i < m; i++){
        while(q > 0 && P[q+1] != P[i])
            q = next[q];
        if(P[q+1] == P[i])
            q += 1;
        next[i] = q;
    }
}

void KMP(void){
    int q = 0;
    for(int i = 1; i < n; i++){
        while(q > 0 && P[q+1] != T[i])
            q = next[q];
        if(P[q+1] == T[i])
            q += 1;
        if(q == m-1){                   //attention "-1"
            cout << "Find it at " << i-(m-1)+1 <<endl;
            q = next[q];
        }
    }
}

int main(void){
    
    T[0] = '0';             //init
    P[0] = '0'; 
    scanf("%s", T+1);           //attention "+1"
    scanf("%s", P+1);
    n = strlen(T);      //attention 
    m = strlen(P);
    FindNext();
    KMP();
    //
        for(int i = 1; i < m; i++)
            cout << next[i] << " ";
        cout << endl;
    return 0;
}
