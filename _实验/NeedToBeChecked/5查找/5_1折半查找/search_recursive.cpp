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

        /* cout << i;
         *
         * for(int k = 0; k < i; k++)
         *     printf("%d ", arr[k]);
         */
    
    //search: 
    cout << "The key you want to find: " <<endl;
    int x;              //The key that you want to find.
    while(scanf("%d", &x) != EOF)
        cout << search(0, i, x) << endl;
    return 0;
} 
int search(int l, int r, int x){
    if(l < r){
        int mid = (l+r)/2;
        if(x < arr[mid])
            return search(l, mid, x);
        else if(x > arr[mid])
            return search(mid+1, r, x);
        else return mid;      
    }
    else return -1;         //failed 
}


/* 有一个问题： 二分查找一个重复的key时，不一定找到的是它第一次出现的位置。
 *
 */
