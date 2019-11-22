#include <iostream>
#include <limits.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int f(int t[8][8], int w, int k){
    //f(t, 0, 3)
    if (k<0 or k>7)
        return INT32_MAX;
    else if (w==7)
        return t[w][k];
    else
        return t[w][k]+min(f(t,w+1,k-1),min(f(t,w+1,k),f(t,w+1,k+1)));
}

int main(){
    int tab[8][8];
    srand(time(NULL));
    for (int i=0; i<8;++i){
        for (int j=0; j<8;++j){
            tab[i][j]=rand()%10;
            cout<<tab[i][j]<<'\t';
        }
        cout<<endl<<endl;
    }
    
    cout<<f(tab,0,4);
    return 0;
}
