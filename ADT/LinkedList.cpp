
//linked list Templat

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


#ifndef _List_H
typedef int/**/ ElementType;

struct node;
typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

/* Place in the implementation file */
struct node{
    ElementType Element;
    Position next;
};

int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(Position P, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position First(List L);
Position Advance(Position P);
void PrintList(List L);

void DeletePosition(Position P, List L);

#endif  /* _List_H */



/*create a header should be written in main() */
int main(void){


    return 0;
}


/* Return true if L is empty */
int IsEmpty(List L){
    return L->next == NULL;
}


/* Return true if P is the last position in the L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, List L){
    return P->next == NULL;
}


/* Return the first Position of X in L; NULL if not found */
Position Find(ElementType X, List L){
    Position P;

    P = L->next;
    while(P != NULL && P->Element != X)
        P = P->next;

    return P;
}


/* Find the Previous Position of the first X; if not, the next field returned position is NULL */
Position FindPrevious(Position P, List L){
    Position Q;
    
    Q = L;

    while(Q->next != NULL && Q->next != P)
        Q = Q->next;

    return Q;
}


/* Insert (after legal position P)*/
/* Parameter L is unused in this implementation */
void Insert(ElementType X, List L, Position P){
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(struct node));
    if(TmpCell == NULL)
        printf("Fail to create a Position! (Insert)");

    TmpCell->Element = X;
    TmpCell->next = P->next;
    P->next = TmpCell;
}


/* DeleteList Algorithm */
void DeleteList(List L){
    Position P, TmpCell;

    P = L->next;
    L->next = NULL;
    while(P != NULL){
        TmpCell = P->next;
        free(P);
        P = TmpCell;
    }
}


void DeletePosition(Position P, List L){
    Position Q;
    Q = FindPrevious(P, L);
    Q->next = P->next;
    free(P);

}

void PrintList(List L){
    Position P;
    P = L->next;

    while(!P){
        cout << P->Element <<" ";
        P = P->next;
    }
    cout << endl;
    return;
}









