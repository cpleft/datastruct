//Stack 
//by Linked List


/* 1. Create a header
 * 2. Insert after the header each time
 *
 * --------------------------------------------
 *         From here to Push or Pop            
 *           V                                
 *     header -> 1 -> 2 -> 3 -> ... -> NULL   
 * --------------------------------------------
 *       
 */

#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;


typedef /* */int Elem;
struct node;
typedef node *PtrtoNode;
typedef PtrtoNode Stack;
struct node{
    Elem x;
    PtrtoNode next;
};

Stack CreateStack();
bool IsEmpty(Stack S);
Elem Pop(Stack S);
void Push(Elem e, Stack S);
Elem Top(Stack S);


Stack CreateStack(){
    Stack S;
    S = (Stack)malloc(sizeof(node));
    if(!S) printf("Out of Space!");

    S->next = NULL;
    return S;
}


bool IsEmpty(Stack S){
    return S->next == NULL;
}

Elem Pop(Stack S){
    Stack P;
    P = S;
    Elem e;

    if(P->next){
        P = P->next;
        e = P->x;
        S->next = P->next;
        free(P);
        return e;
    }
    else printf("Stack is Empty!");

}

void Push(Elem e, Stack S){
    Stack P;
    P = (Stack)malloc(sizeof(node));
    if(!P) printf("Out of Space!");

    P->x = e;
    P->next = S->next;
    S->next = P;
    
    return;
}

Elem Top(Stack S){
    if(S->next != NULL)
        return S->next->x;

    else printf("Stack is Empty!");
}


int main(void){

    return 0;
}
