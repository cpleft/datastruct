//Make data file: 
//Build a file named "data", with random interger numbers in it.
//random numbers from 0 to 9999
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int main(void){
    FILE *fp;
    if((fp = fopen("data.txt", "w")) == NULL){     //failed to open the file.
        cout << "The file cannot be open." <<endl;
        exit(1);
    }
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 150; i++){
        for(int j = 0; j < 15; j++)
            fprintf(fp, "%d ", rand()%10000);
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}
