//First copy the numbers form "data" file to an array, and sort it.
//Then start search.
#include<cstdio>
#include<iostream>
#include<algorithm>
#define M 5000
using namespace std;

int search(int l, int r, int x);
int arr[M];

int main(void){
    FILE *fp;
    if((fp = fopen("data.txt", "r")) == NULL){
        cout << "Failed to open file data.txt" <<endl;
        exit(1);
    }
    int i = 0;
    while(!feof(fp)){
        fscanf(fp, "%d", arr+i);
        i++;
    }
    sort(arr, arr + i);
    //successfully sorted.

    //search: 
    cout << "The key that you want to find: " <<endl;
    int x;      //key you want
    while(scanf("%d", &x) != EOF)
        cout << search(0, i, x) <<endl;
    return 0;
} 
int search(int l, int r, int x){
    while(l < r){
        int mid = (l+r)/2;
        if(x < arr[mid])
            r = mid;
        else if(x > arr[mid])
            l = mid+1;
        else return mid;
    }
    return -1;      //failed 
}
