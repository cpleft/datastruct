#include<cstdio>
#include<iostream>
using namespace std;

typedef struct{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct{
    BiTNode *root;
    int num;
}Tree;

/* functions declaration
 */
void InitBiTree(Tree T);
void DestroyTree(Tree T);


void InitBiTree(Tree T){
    T = (*Tree)malloc(sizeof(Tree));
    if(!T){
        cout << "Out of space!" <<endl;
        return ;
    }

    T.root = NULL;
    T.num = 0;
}

