#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node;
typedef struct node *ToNode;
typedef ToNode List;
typedef ToNode Position;
struct node{
    int e;
    double c;
    Position next;
};

void CreateList(List L);
List Add(List X, List Y);
List Subtract(List X, List Y);
void Print(List L);

int main(void){
    List A, B, C, D;
    CreateList(A);
    CreateList(B);

    C = Add(A, B);
    D = Subtract(A, B);

    Print(A);
    Print(B);
    return 0;
}

void CreateList(List L){
    L = (List)malloc(sizeof(node));
    if(!L) return;
    L -> next = NULL;
    int n;
    int cx, ex;

    Position P;
    P = (List)malloc(sizeof(node));
    if(!P) return;
    P -> next = L -> next;
    L -> next = P;

    cin >> n;
    //for the first time to insert 
    cin >> cx >> ex;
    P -> c = cx; P -> e = ex;

    //other times
    for(int i = 1; i < n; i++){
        P = L;
        Position Q;
        Q = (Position)malloc(sizeof(node));
        cin >> cx >> ex;
        Q -> c = cx; Q -> e = ex;

        while(P -> next != NULL && P -> next -> e >= Q -> e){
            if(P -> next -> e = Q -> e){
                P -> next -> c += Q -> c;

                //reckon on function Print
                if(P -> next -> c ==0){
                    Position O = P -> next;
                    P -> next = P -> next -> next;
                    free(O);
                }
            }
            else {
                Q -> next = P -> next;
                P -> next = Q;
            }
            P = P -> next;
        }
    }
}

List Add(List X, List Y){
    //Create a new header
    List L = (List)malloc(sizeof(node));
    if(!L) return X;
    L -> next = NULL;

    X = X -> next;
    Y = Y -> next;
    
    while(X != NULL || Y != NULL){
        if(X -> e < Y -> e){
            Position P = X;
            X = X -> next;

            P -> next = L -> next;
            L -> next = P;

            L = L -> next;
        }
        else if(X -> e == Y -> e){
            Position P = X; 
            Position Q = Y;
            X = X -> next;
            Y = Y -> next;

            P -> c += Q -> c;
            //reckon on function Print
            if(P -> c == 0){
                break;
            }
            else{
                P -> next = L -> next;
                L -> next = P;

                L = L -> next;
            }
        }
        else{
            Position P = Y;
            Y = Y -> next;

            P -> next = L -> next;
            L -> next = P;

            L = L -> next;
        }
    }
    return L;
}

List Subtract(List X, List Y){
    //Create a new header
    List L = (List)malloc(sizeof(node));
    if(!L) return X;
    L -> next = NULL;

    X = X -> next;
    Y = Y -> next;
    
    while(X != NULL || Y != NULL){
        if(X -> e < Y -> e){
            Position P = X;
            X = X -> next;

            P -> next = L -> next;
            L -> next = P;

            L = L -> next;
        }
        else if(X -> e == Y -> e){
            Position P = X; 
            Position Q = Y;
            X = X -> next;
            Y = Y -> next;

            P -> c -= Q -> c;
            //
            if(P -> c == 0){
                break;
            }
            else{
                P -> next = L -> next;
                L -> next = P;

                L = L -> next;
            }
        }
        else{
            Position P = Y;
            Y = Y -> next;

            P -> c = -(P -> c);

            P -> next = L -> next;
            L -> next = P;

            L = L -> next;
        }
    }
    return L;

}

void Print(List L){
    Position P;
    P = L -> next;

    while(!P){
        cout << P -> c << " " << P -> e << " ";
        P = P -> next;
    }
    cout << endl;
    return;

}
