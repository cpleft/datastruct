

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


typedef int/**/ ElementType;

struct node;
typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
void DeletePoistion_1(List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void PrintList(List L);


/* Place in the implementation file */
struct node{
    ElementType Element;
    Position next;
};


/*create a header should be written in main() */
int main(void){
    List L;
    //create header
    L = (Position)malloc(sizeof(node));
    if(!L){
        printf("Failed in creating a List!");
        return 0;
    }
    L->next = NULL;
    
    int e;
    while(scanf("%d", &e) && e != 0){
        Insert(e, L, L);
    }

    while(L->next != NULL){
        PrintList(L);
        DeletePoistion_1(L);
    }
    printf("empty list!\n");
    return 0;
}


/**/
List MakeEmpty(List L){

}


void DeletePoistion_1(List L){
    Position P;

    P = L->next;
    if(P){
        L->next = P->next;
        free(P);
    }
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

/*Delete the first occurrence of X from L; if X is not found, do nothing */
void Delete(ElementType X, List L){
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if(!IsLast(P, L)){
        TmpCell = P->next;
        P->next = TmpCell->next;
        free(TmpCell);
    }

    return;
}


/* Find the Previous Position of the first X; if not, the next field returned position is NULL */
Position FindPrevious(ElementType X, List L){
    Position P;
    
    P = L;

    while(P->next != NULL && P->Element != X)
        P = P->next;

    return P;
}


/* Insert (after legal position P)*/
/* Parameter L is unused in this implementation */
void Insert(ElementType X, List L, Position P){
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(struct node));
    if(TmpCell == NULL){
        printf("Fail to create a Position! (Insert)");
        return;
    }

    TmpCell->Element = X;
    TmpCell->next = P->next;
    P->next = TmpCell;
    return ;
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



void PrintList(List L){
    Position P;
    P = L->next;

    while(P){
        cout << P->Element <<" ";
        P = P->next;
    }
    cout << endl;
    return;
}









