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

void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);


/* 递归
void PreOrderTraverse(BiTree T){
    if(T){
        cout << T->data << endl;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(BiTree lchild);
        cout << T->data << endl;
        InOrderTraverse(BiTree rchild);
    }
}
void PostOrderTraverse(BiTree T){
    if(T){
        PostOrderTraverse(BiTree lchild);
        PostOrderTraverse(BiTree rchild);
        cout << T->data << endl;
    }
}
*/
/* 非递归
 */
/*对于任一结点p：

        a. 访问结点p，并将结点p入栈；

        b. 判断结点p的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点p，循环置a；若不为空，则将p的左孩子置为当前结点p；

        c. 直到p为空，并且栈为空，则遍历结束。
 */
void PreOrderTraverse(BiTree T){
    stack<BiTNode> S;               //STL stack
    BiTree p = T;
    if(p == NULL) {
        cout << "the traverse is from a NULL node" <<endl;
        return ;
    }
    while(p != NULL || !S.empty()){
        while(p != NULL){
            S.push(p);
            cout << p->data <<endl;
            p = p->lchild;
        }
        if(!S.empty()){
            S.pop();
            p = p->rchild;
        }
    }
}


/*     对于任一结点：

       a. 若其左孩子不为空，则将p入栈，并将p的左孩子设置为当前的p，然后对当前结点再进行相同的操作；

       b. 若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的p置为栈顶结点的右孩子；

       c. 直到p为空并且栈为空，则遍历结束。
 */
void InOrderTraverse(BiTree T){
    stack<BiTNode> S;
    BiTree p = T;
    if(p == NULL) {
        cout << "the traverse is from a NULL node" <<endl;
        return ;
    }
    
    while(p != NULL || !S.empty()){
        while(p != NULL){
            S.push(p);
            p = p->lchild;
        }
        if(!S.empty()){
            S.pop();
            cout << p->data << endl;
            p = p->rchild;
        }
    }
}


/*     要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点p，先将其入栈。若p不存在左孩子和右孩子，则可以直接访问它，或者p存在左孩子或右孩子，但是其左孩子和右孩子都已经被访问过了，则同样可以直接访问该结点。若非上述两种情况，则将p的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子之前别访问，左孩子和右孩子都在根结点前面被访问。
 */
void PostOrderTraverse(BiTree T){
}


