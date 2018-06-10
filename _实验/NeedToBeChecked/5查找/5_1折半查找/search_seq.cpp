#include<cstdio>
#include<iostream>
#include<algorithm>
#define M 5000
using namespace std;

int search(void);
int arr[M];
int i;

int main(void){
    FILE *fp;
    if((fp = fopen("data.txt", "r")) == NULL){
        cout << "Failed to open file data.txt" <<endl;
        exit(1);
    }
    i = 1;
    while(!feof(fp)){
        fscanf(fp, "%d", arr+i);
        i++;
    }

    //search: 
    cout << "The key that you want to find: " <<endl;
    int x;      //key you want
    while(scanf("%d", &x) != EOF){
        arr[0] = x;
        cout << "Finded in :"<< search() <<endl;
    }
    return 0;
} 

int search(void){
    for(int k = i-1; k >=0 ; k--){
        if(arr[k] == arr[0])
            return k;
    }
}
