#include<cstdio>
#include<iostream>
#include<cstring>
#define M 230
using namespace std;

char T[M];                       //text
char P[M];                       //pattern
int next[M];                     //next array
int n, m;
int lsum = 0;
int sum = 0;

void FindNext(void){
    int q = 0;
    next[0] = 0;
    next[1] = 0;
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
        if(q > 0 && P[q+1] != T[i])
            q = next[q];
        if(P[q+1] == T[i])
            q += 1;
        if(q == m-1){           //sucessfully matched
            lsum ++;
            sum ++;
            cout << i-m+2 << " ";
        }
    }
}

int main(void){
    T[0] = ' ';
    P[0] = ' ';
    scanf("%s", P+1);           //input P
    FindNext();
    int i = 1;                      //ith line
    while(scanf("%s", T+1) != EOF){
        lsum = 0;
        n = strlen(T);
        m = strlen(P);
        
        FindNext();
        cout << "第" << i << "行 ";
        KMP();
        cout << "共" << lsum << "个" << endl;
        i++;
    }
    cout << sum << endl;
    return 0;
}
