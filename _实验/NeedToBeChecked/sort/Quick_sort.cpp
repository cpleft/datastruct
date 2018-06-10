//have a bug : When given 10000, it's too sow!  Is my Implementation is wrong?
//快速排序
/* 
 * 假设要排序的数都是整数
 * 要排序的数存储在数组Num中; 数的个数是n
 * 数是从数组下标0开始
 */
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

#define M 30000                              //M < 10^6 (栈的大小)
typedef int Elem;
Elem Num[M];
int N;

void Input(void);
Elem Median3(int l, int r);                 // l, r 是闭区间
void Qsort(int l, int r);
int TimesForCmp = 0;
int TimesForTmp = 0;

Elem Median3(int l, int r){
    int center = (l+r+1)/2;
    if(Num[l] > Num[center]){
        Elem tmp = Num[l];
        Num[l] = Num[center];
        Num[center] = tmp;
    }
    if(Num[l] > Num[r]){
        Elem tmp = Num[l];
        Num[l] = Num[r];
        Num[r] = tmp;
    }
    if(Num[center] > Num[r]){
        Elem tmp = Num[center];
        Num[center] = Num[r];
        Num[r] = tmp;
    }

    //swap Num[r] and Num[center]
    Elem tmp = Num[r];
    Num[r] = Num[center];
    Num[center] = tmp;

    return Num[r];
}
void Qsort(int l, int r){
    if(l < r){
        Elem Pivot = Median3(l, r);
        int i = l, j = r-1;
        for(;;){
            while(Num[++i] < Pivot) { TimesForCmp++;}
            while(Num[--j] > Pivot) { TimesForCmp++;}      //==0时，停顿
                            //i is bigger than j is impossible.
            if(i < j){                      //swap
                Elem tmp = Num[i];
                Num[i] = Num[j];
                Num[j] = tmp;

                TimesForTmp ++;
            }
            else break;
        }
        //swap Num[r](Pivot) and Num[i]
        Elem tmp = Num[i];
        Num[i] = Num[r];
        Num[r] = tmp;
        
        Qsort(l, i-1);
        Qsort(i+1, r);
    }
}
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

int main(void){
    Input();
    Qsort(0, N-1);
    //output
    FILE *fp;
    if((fp = fopen("Result.txt", "w")) == NULL){     //failed to open the file.
        cout << "The file cannot be open." <<endl;
        exit(1);
    }
    
    fprintf(fp, "Quick_sort :");
    for(int i = 0; i < N; i++){
        if(i%15 == 0) fprintf(fp, "\n");
        fprintf(fp, "%d ", Num[i]);
    }
    fprintf(fp, "\nTimesForCmp: %d\n", TimesForCmp);
    fprintf(fp, "TimesForTmp: %d\n", TimesForTmp);
    fclose(fp);
}


/* 备注： 
 * 出现的bug
 *  for(;;){
        while(Num[i] < Pivot) {i++; TimesForCmp++;}
        while(Num[j] > Pivot) {j--; TimesForCmp++;}      //==0时，停顿
//这种写法的while在遇到有多个值为Pivot的数时会停止不前！

        if(i < j){                      //swap
            Elem tmp = Num[i];
            Num[i] = Num[j];
            Num[j] = tmp;

            TimesForTmp ++;
        }
        else break;
    }

    */
