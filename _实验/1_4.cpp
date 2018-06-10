//linked list Templat


#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


typedef double/**/ ElementType;

struct node;
typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void PrintList(List L);

void CreateList(List L);
void Print(List L);
void Add(List X, List Y, List Z);
void Subtract(List X, List Y, List Z);



/* Place in the implementation file */
struct node{
    ElementType Element;
    int p;
    Position next;
};



/**/
List MakeEmpty(List L){

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
Position Find(int X, List L){
    Position P;

    P = L->next;
    while(P != NULL && P->p != X)
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

void CreateList(List L){
    Position TmpCell;
    TmpCell = L;
    for(int i = 1; i <= 205; i++){//0 ~ 204
        Position P;
        P = (Position)malloc(sizeof(node));
        if(!P){
            printf("Failed in create List_200!\n");
            return ;
        }
        P->Element = 0;
        P->p = 205 - i;
        TmpCell->next = P;
        TmpCell = P;
    }
    TmpCell->next = NULL;

    return;
}

void Print(List L){
    Position P;
    P = L->next;

    int sum = 0;
    while(P){
        if(P->Element != 0)
            sum++;
        P = P->next;
    }
    P = L->next;
    cout << sum <<" ";
    while(P){
        if(P->Element != 0){
            cout << P->Element <<" "<< P->p <<" ";
        }
        P = P->next;
    }
    cout<< endl;
} 


void Add(List X, List Y, List Z){
    Position P, Q, R;
    P = X->next;
    Q = Y->next;
    R = Z->next;

    while(P){
        R->Element = P->Element + Q->Element;
        P = P->next;
        Q = Q->next;
        R = R->next;
    }
}
void Subtract(List X, List Y, List Z){
    Position P, Q, R;
    P = X->next;
    Q = Y->next;
    R = Z->next;

    while(P){
        R->Element = P->Element - Q->Element;
        P = P->next;
        Q = Q->next;
        R = R->next;
    }
}


/*create a header should be written in main() */
int main(void){
    List A, B, C, D;
    A = (List)malloc(sizeof(node));
    B = (List)malloc(sizeof(node));
    C = (List)malloc(sizeof(node));
    D = (List)malloc(sizeof(node));
    if(!A || !B || !C || !D){
        printf("failed in create List\n");
        return 0;
    }
    
    CreateList(A);
    CreateList(B);
    CreateList(C);
    CreateList(D);


    //input
    int p;
    double x;
    cout <<"input A"<< endl;
    while(scanf("%lf%d", &x, &p) && (p != 0 || x != 0)){
        Position P;
        P = Find(p, A);
        P->Element = x;
    }
    cout <<"input B"<< endl;
    while(scanf("%lf%d", &x, &p) && (p != 0 || x != 0)){
        Position P;
        P = Find(p, B);
        P->Element = x;
    }

    Add(A, B, C);
    Subtract(A, B, D);

    Print(C);
    Print(D);
    return 0;
}









