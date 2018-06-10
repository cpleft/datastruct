#include<cstdio>
#include<iostream>
using namespace std;

//string 
typedef struct{
    char* ch;
    int length;
}Str;

//declare functions
int StrLength(Str s);
Str StrAssign(Str s1, Str s2);             //Assign s2 to s1
Str StrConcat(Str s1, Str s2);
Str SubStr(Str s, int i, int len);
int StrCmp(Str s1, Str s2);
int StrIndex(Str s, Str t);
Str StrInsert(Str s, int i, Str t);
Str StrDel(Str s, int i, int len);
Str StrRep(Str s, Str t, Str r);


int StrLength(Str s){
    return s.length;
}

// Assign s2 to s1
Str StrAssign(Str s1, Str s2){
    if(s1.ch) free(s1.ch);                  //free the old 
    s1.ch = (*char)malloc(sizeof(char)*s2.length);
    if(!s1.ch){ 
        cout << "overflow" <<endl;
        return s2;
    }
    s1.length = s2.length;
    return s1;
}

//return s1&s2
Str StrConcat(Str s1, Str s2){
    Str s;
    s.length = s1.length + s2.length;
    s.ch = (char*)malloc(sizeof(char)*s.length);
    if(!s.ch) {
        cout << "overflow" <<endl; 
        return s1;
    }

    for(int i = 0; i < s1.length; i++)
        s.ch[i] = s1.ch[i];
    for(int i = s1.length; i < s.length; i++)
        s.ch[i] = s2.ch[i];
    return s; 
}

//return s` = s[i-1 ~ i-2+len]
Str SubStr(Str s, int i, int len){
    //
    if(i < 1 || i > s.length || len > s.length-i+1 || len < 0){
        cout << "Incorrect value len" <<endl;
        return s;
    }

    Str s_;
    s_.length = len;
    s_.ch = (char*)malloc(sizeof(char)*s_.length);
    if(!s_.ch) cout << "overflow" <<endl;
    
    int k = 0;
    for(int j = i; j <= i+len-2; j++, k++)
        s_.ch[k] = s.ch[j];
}

/*
 * if s1 < s2 , return -x;
 * if s1 == s2 , return 0;
 * if s1 > s2 , return +x;
 */
int StrCmp(Str s1, Str s2){
    if(s1.length < s2.length) return -1;
    else if (s1.length > s2.length) return 1;
    else for(int i = 0; i < s1.length; i++)
            if(s1.ch[i] != s2.ch[i]) return 2;
    return 0;
}

// find the first position 
// \(time to study KMP\)
int StrIndex(Str s, Str t){
    int next[100];
    
}


Str StrInsert(Str s, int i, Str t){
    if(i < 1 || i > s.length) {
        cout << "Failed" <<endl;
        return s;
    }
    Str _;
    _.length = t.length + s.length;
    _ = (char*) malloc(sizeof(char)*_.length);
    if(!_){
        cout << "overflowed" <<endl;
        return s;
    }
    for(int j = 0; j < i-1; j++)
        _.ch[j] = s.ch[j];
    int k = 0;
    for(int j = i-1; j < i-1+t.length; j++, k++)
        _.ch[j] = t.ch[k];
    int l = 0;
    for(int j = i-1+t.length; j < _.length; j++, l++)
        _.ch[j] = s.ch[i-1+l];
    
    return _;
}

Str StrDel(Str s, int i, int len){
    Str _;
    _.length = s.length - len;
    _ = (char*) malloc(sizeof(char)*_.length);
    if(!_){
        cout << "overflowed" <<endl;
        return s;
    }
    int k = 0;
    for(int j = 0; j < i-1; j++, k++)
        _.ch[k] = s.ch[j];
    for(int j = i-2+len; j < s.length; j++, k++)
        _.ch[k] = s.ch[j];
    return _;

}

Str StrRep(Str s, Str t, Str r){
}











