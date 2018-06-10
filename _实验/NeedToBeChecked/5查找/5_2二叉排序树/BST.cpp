//Implement a binary search tree.
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

struct TreeNode;
typedef TreeNode *BSTree;     //BSTree 
typedef BSTree Position;   //Position        
typedef int/**/ Elem;
 
/* functions */
Position Find(Elem x, BSTree T);    //return NULL when x can't be found.
BSTree Insert(Elem x, BSTree T);
BSTree Delete(Elem x, BSTree T);
Position FindMin(BSTree T);
void InorderTravel(BSTree T);
BSTree CreateTree(void);

/* node */
struct TreeNode{
    Elem key;
    Position lchild;
    Position rchild;
};

/* implementations */
Position Find(Elem x, BSTree T){    //return NULL when x can't be found.
    if(T == NULL){
        cout << "Failed to find x" <<endl;
        return NULL;
    }
    else if(x > T->key)
        return Find(x, T->rchild);
    else if(x < T->key)
        return Find(x, T->lchild);
    else
        return T;       //sucessfully find 
}

BSTree Insert(Elem x, BSTree T){
    if(T == NULL){      //where to insert
        //build a node
        Position p;
        p = (Position)malloc(sizeof(TreeNode));
        if(!p){
            cout << "Overflowed" <<endl;
            exit(1);
        }

        //insert
        p->key = x;
        p->lchild = NULL;
        p->rchild = NULL;
        T = p;
    }
    else if(x > T->key)
        T->rchild = Insert(x, T->rchild);
    else if(x < T->key)
        T->lchild = Insert(x, T->lchild);
    //else, found the x, do nothing 

    return T;
}

BSTree Delete(Elem x, BSTree T){
    Position TmpCell;
    //first: find
    if(T == NULL){
        cout << "Failed to find x" <<endl;
        exit(1);
    }
    else if(x > T->key)
        T->rchild = Delete(x, T->rchild);
    else if(x < T->key)
        T->lchild = Delete(x, T->lchild);
    else{           //sucessfully find
        //T have two children
        if(T->lchild && T->rchild){
            TmpCell = FindMin(T->rchild);
            T->key = TmpCell->key;
            T->rchild = Delete(T->key, T->rchild);
        }
        //T have one or o child
        else{       
            TmpCell = T;
            if(T->lchild == NULL)
                T = T->rchild;
            else if(T->rchild == NULL)
                T = T->lchild;
            free(TmpCell);
        }
    }
    return T;
}

Position FindMin(BSTree T){
    if(T == NULL){          // Failed to find
    }
    else if(T->lchild)
        return FindMin(T->lchild);
    else                   // Sucessfully find
        return T;
}
