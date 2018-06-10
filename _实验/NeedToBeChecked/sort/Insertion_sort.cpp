//插入排序
/* 假设要排序的数都是整数
 * 要排序的数存储在数组Num中; 数的个数是n
 * 数是从数组下标0开始
 */
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

#define M 30000                              //M < 10^6 (栈的大小)
int Num[M];
int N;

void Input(void);
void Insertion_sort(void);
int TimesForCmp = 0;
int TimesForTmp = 0;

void Input(void){
    FILE *fp;
    if((fp=fopen("intfile.txt", "r")) == NULL){     // "r"
        cout << "The file can't be open " << endl;
        exit(1);
    }
    int i = 0;
    while(fscanf(fp, "%d", Num+i) != EOF)
        i++;
    N = i;
    fclose(fp);
    return;
}

void Insertion_sort(void){
    for(int i = 1; i < N; i++){
        int Tmp = Num[i];
        int q;
        for(q = i; q>0 && Num[q-1]>Tmp; q--){
            Num[q] = Num[q-1];

            TimesForTmp ++;
            TimesForCmp ++;
        }
        Num[q] = Tmp;
    }
    return;
}


int main(void){
    Input();
    Insertion_sort();
    //output
    FILE *fp;
    if((fp = fopen("Result.txt", "w")) == NULL){     //failed to open the file.
        cout << "The file cannot be open." <<endl;
        exit(1);
    }
    
    fprintf(fp, "Insertion_sort :");
    for(int i = 0; i < N; i++){
        if(i%15 == 0) fprintf(fp, "\n");
        fprintf(fp, "%d ", Num[i]);
    }
    fprintf(fp, "\nTimesForCmp: %d\n", TimesForCmp);
    fprintf(fp, "TimesForTmp: %d\n", TimesForTmp);
    fclose(fp);
}
