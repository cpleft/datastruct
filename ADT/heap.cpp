//use array. Must start with NO.1

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

void shiftdown(int i);
void shiftup(int i);
void hs();
void build();
int deletemin();
void swap(int i, int j);

//It is a minimum heap.

int n;//size of heap, from 0 on
const int M = 100000 + 100;
int heap[M];//use array. Must start with NO.1

//to delete
void shiftdown(int i){//from point to start
    int flag = 0, t;
    while(flag == 0 && 2 * i <= n){
        //left subtree
        if(heap[i] > heap[2 * i])
            t = 2 * i;
        else t = i;

        //right subtree
        if(i * 2 + 1 <= n){
            if(heap[t] > heap[2 * i + 1])
                t = 2 * i + 1;
        }

        //
        if(t != i){
            swap(i, t);
            i = t;
        }
        else flag = 1;
    }

}

//to insert
void shiftup(int i){
    if(i == 1) return;
    int flag = 0;

    while(i != 1 && flag == 0){
        if(heap[i] < heap[i / 2]){
            swap(i, i / 2);
            i = i / 2;
        }
        else flag = 1;
    }
}

int deletemin(){
    int t;
    t = heap[1];

    heap[1] = heap[n];
    n--;
    shiftdown(1);

    //return the minium number
    return t;
}


void swap(int i, int j){
    int temp;
    temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;

    return;
}
    
void build(){
    //从最后一个非叶节点开始依次向下调整
    for(int i = n / 2; i > 0; i--){
        shiftdown(i);
    }
    return;
}

//heap sort
void hs(){
    while(n > 1){
        //pop
        swap(1, n);
        n--;
        shiftdown(1);
    }
    return;
}


int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> heap[i];
    heap[0] = 0;

    int num = n;
    //
    build();

    int ans = 0;
    for(int i = 2; i <= num; i++){
        int temp = 0;
        temp += deletemin();
        temp += deletemin();
        ans += temp;
        heap[n + 1] = temp;
        shiftup(n + 1);
