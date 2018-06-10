//选择排序
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
void Selection_sort(void);
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

void Selection_sort(void){
    for(int i = 0; i < N; i++){
        int MinNum = i;
        int Min = Num[i];
        for(int j = i; j < N; j++)
            if(Min > Num[j]){
                Min = Num[j];
                MinNum = j;

                TimesForCmp ++;
            }
        for(int j = MinNum; j > i; j--){
            Num[j] = Num[j-1];

            TimesForTmp ++;
        }
        Num[i] = Min;
    }
    return;
}


int main(void){
    Input();
    Selection_sort();
    //output
    FILE *fp;
    if((fp = fopen("Result.txt", "w")) == NULL){     //failed to open the file.
        cout << "The file cannot be open." <<endl;
        exit(1);
    }
    
    fprintf(fp, "Selection_sort : ");
    for(int i = 0; i < N; i++){
        if(i%15 == 0) fprintf(fp, "\n");
        fprintf(fp, "%d ", Num[i]);
    }
    fprintf(fp, "\nTimesForCmp: %d\n", TimesForCmp);
    fprintf(fp, "TimesForTmp: %d\n", TimesForTmp);
    fclose(fp);
}
