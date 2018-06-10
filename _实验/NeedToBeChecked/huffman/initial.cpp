/*
 * 从终端(键盘)读入字符集的大小 n,n 个字符及 n 个权值,建
立哈夫曼树并将其存于文件 hfmTree 中
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;

#define M 3000
struct TreeNode;
typedef TreeNode *PtrTree;
struct TreeNode{
    char ch;
    double pos;             //possibility
    TreeNode* lchild;
    TreeNode* rchild;
};

struct cmp{
    bool operator()(PtrTree a, PtrTree b){
        return a->pos < b->pos;
    }
};
priority_queue<PtrTree, vector<PtrTree>, cmp> q;     //claim priority_queue
typedef vector<bool> Hfm_code; 
map<char, Hfm_code> Hfm_dic;

int n;
void Input(void){           //Input and push them in the p_q
    cin >> n;
    for(int i = 0; i < n; i++){
        char ch;
        double pos;
        cin >> ch >> pos;

        PtrTree ptr = (PtrTree)malloc(sizeof(TreeNode));
        if(!ptr) return;

        ptr->ch = ch;
        ptr->pos = pos;
        ptr->lchild = ptr->rchild = NULL;

        q.push(ptr);
    }
}

PtrTree CreatTree(void){       //Create huffman tree.
    PtrTree Tr;
    for(int i = 0; i < n-1; i++){
        PtrTree l,r;
        l = q.top();
        q.pop();
        r = q.top();
        q.pop();

        PtrTree T;
        T = (PtrTree)malloc(sizeof(TreeNode));
        if(!T) return NULL;

        T->pos = l->pos + r->pos;
        T->lchild = l;
        T->rchild = r;
        
        Tr = T;
    }
    return Tr;
}

void Travel(PtrTree T, Hfm_code curcode){          //Travel and figure out codings in the array.
    if(T){
        if(!T->lchild && !T->rchild){  //leaf node
            Hfm_dic[T->ch] = curcode;
        }
        else{
            Hfm_code lcode = curcode;
            Hfm_code rcode = curcode;
            lcode.push_back(false);
            rcode.push_back(true);
            Travel(T->lchild, lcode);
            Travel(T->rchild, rcode);
        }
    }
}

void Output(void){          //Output to "HfmTree" file.
    for(map<char,Hfm_code>::iterator it = Hfm_dic.begin(); it != Hfm_dic.end(); it++)  
    {  
        cout<<(*it).first<<'\t';  
        copy(it->second.begin(),it->second.end(),std::ostream_iterator<bool>(cout));  
        cout << endl;  
    } 
}

int main(void){
    Input();
    PtrTree T;
    T = CreatTree();
    Hfm_code nullcode;
    nullcode.clear();
    Travel(T, nullcode);
    Output();
    return 0;
}
