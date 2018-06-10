
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;

int arr[20000];
int main(void){
    FILE *fp;
    if((fp = fopen("data.txt", "r")) == NULL){     //failed to open the file.
        cout << "The file cannot be open." <<endl;
        exit(1);
    }
    int i = 0;
    while(!feof(fp)){
        fscanf(fp, "%d", arr+i);
        i++;
    }
    sort(arr, arr + i);
    fclose(fp);

    FILE *fp_;
    if((fp_ = fopen("SortedFile.txt", "w")) == NULL){     //failed to open the file.
        cout << "The file cannot be open." <<endl;
        exit(1);
    }
    for(int k = 0; k < i; k++){
        if(k % 15 == 0) fprintf(fp_, "\n");
        fprintf(fp_, "%d ", arr[k]);
    }

    return 0;
}
