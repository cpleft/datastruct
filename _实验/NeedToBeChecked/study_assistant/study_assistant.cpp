#include<cstdio>
#include<iostream>
#include<cstring>
#define M 2300
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

    while(scanf("%s", P+1) != EOF){ 
        int i = 0;
        char buffer[M];
        int j = 0;
        char ch;
        FILE *fp;
        fp = fopen("x.txt", "r");
        while(!feof(fp)){
            while((ch = getchar(fp)) != '\n'){
                buffer[j] = ch;
                j++;
            }
            i++;            //line ++
            // from array "buffer" scanf %s 
            int k = 0;
            
            // kmp
            //... 
        }
        fclose(fp);

    }
    return 0;
}
