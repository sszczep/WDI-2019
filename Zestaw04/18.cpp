#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <limits.h>
#define MAX 15

using namespace std;

int f(int t[MAX][MAX]){
    int max_sum=INT32_MIN,sumw=0,sumk=0;

    for (int i =0; i<MAX; ++i){
        for (int a_1=0; a_1<MAX-1;++a_1){
            sumw=t[i][a_1];
            sumk=t[a_1][i];
            for (int a_n=a_1+1; a_n<MAX and a_n-a_1+1<=10;++a_n){
                sumw+=t[i][a_n];
                sumk+=t[a_n][i];
                max_sum=max(max_sum,max(sumw,sumk));
            }
        }
    }

    return max_sum;
}

int main(){
    srand(time(NULL));
    int t[MAX][MAX];
    for (int i=0;i<MAX;++i){
        for (int j = 0; j < MAX; j++){
            t[i][j]=rand()%100-50;
            cout<<t[i][j]<<'\t';}
        cout<<endl<<endl;
    }
        
    cout<<f(t);
    return 0;
}
