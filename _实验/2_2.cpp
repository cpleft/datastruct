// 括号匹配
// '\n' 作为表达式的结束符 和 换行符 要注意！
#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

bool Judge(void);

int main(void){
    int n;
    cin >> n;
    getchar(); //!
    while(n--){
        int s;
        s = Judge();
        cout << s << endl;
    }
    return 0;
}

// judge it by line
bool Judge(void){
    char c;
    stack<char> S;
    while((c=getchar()) != '\n'){
        if( c == '(' || c == '{' || c == '[' )
            S.push(c);
        if( c == ')' ){
            if( (!S.empty() && S.top() != '(') || S.empty() ) return false;
            else S.pop();
        }
        if( c == '}' ){
            if( (!S.empty() && S.top() != '{') || S.empty() ) return false;
            else S.pop();
        }
        if( c == ']' ){
            if( (!S.empty() && S.top() != '[') || S.empty() ) return false;
            else S.pop();
        }
    } 
    //if stack is empty, it is true 
    //else it is false
    if(S.empty()) return true;
    else return false;
}
