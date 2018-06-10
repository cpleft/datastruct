#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

struct Complex;
typedef struct Complex *Opr;

struct Complex{
    double a, b;
};


/* Should malloc in main() */

void Assign(Opr Z, double x, double y);
double GetReal(Opr Z);
double GetImage(Opr Z);
void Add(Opr X, Opr Y, Opr Z);
void Subtract(Opr X, Opr Y, Opr Z);
void Multiply(Opr X, Opr Y, Opr Z);
void Divide(Opr X, Opr Y, Opr Z);
void Destroy(Opr Z);


/* assign value */
void Assign(Opr Z, double x, double y){
    Z->a = x;
    Z->b = y;
    return;
}

/* Get Real number */
double GetReal(Opr Z){
    if(Z == NULL) return 0;
    return Z->a;
}

/* Get image number */
double GetImage(Opr Z){
    if(Z == NULL) return 0;
    return Z->b;
}

/* Add X and Y to Z */
void Add(Opr X, Opr Y, Opr Z){
    Z->a = X->a + Y->a;
    Z->b = X->b + Y->b;
    return ;
}

/* Subtract Y from X to Z */
void Subtract(Opr X, Opr Y, Opr Z){
    Z->a = X->a - Y->a;
    Z->b = X->b - Y->b;
    return ;
}

/*Multiply X and Y to Z */
void Multiply(Opr X, Opr Y, Opr Z){
    double a = X->a;
    double b = X->b;
    double c = Y->a;
    double d = Y->b;

    Z->a = a*c - b*d;
    Z->b = b*c + a*d;

    return ;
}

/*Divide Y from X to Z */
void Divide(Opr X, Opr Y, Opr Z){
    double a = X->a;
    double b = X->b;
    double c = Y->a;
    double d = Y->b;

    Z->a = (a*c + b*d)/(c*c + d*d);
    Z->b = (b*c - a*d)/(c*c + d*d);

    return;
}


void Destroy(Opr Z){
    free(Z);
    
    return;
}

int main(void){
    Opr A, B, C, D;
    A = (Opr)malloc(sizeof(Complex));
    B = (Opr)malloc(sizeof(Complex));
    C = (Opr)malloc(sizeof(Complex));
    D = (Opr)malloc(sizeof(Complex));
    if (!A || !B || !C || !D) return 0;

    Assign(A, 1, 1);
    Assign(B, 1, 1);
    Add(A, B, C);
    Subtract(A, B, D);


    cout << GetReal(C) << GetImage(C) <<endl;
    cout << GetReal(D) << GetImage(D) <<endl;
    
    return 0;
}


    




