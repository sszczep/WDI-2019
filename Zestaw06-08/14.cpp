#include <iostream>
#include <limits.h>
#include <time.h>
#include <cstdlib>

using namespace std;

bool moznaPostawic (bool t[8][8], short w, short k){
    
    //sprawdzamy ten sam wiersz i kolumnę
    for (int i=0; i<8; ++i){
        if (t[w][i]==true or t[i][k]==true) return false;
    }

    //idziemy przekątną w lewą górę
    for (int i=w-1,j=k-1;i>=0 and j>=0;i--,j--){
        if (t[i][j]==true) return false;
    }

    //prawo-dół
    for (int i=w+1,j=k+1;i<8 and j<8;i++,j++){
        if (t[i][j]==true) return false;
    }

    //prawo-góra
    for (int i=w-1,j=k+1;i>=0 and j<8;i--,j++){
        if (t[i][j]==true) return false;
    }

    //lewo-dół
    for (int i=w+1,j=k-1;i<8 and j>=0;i++,j--){
        if (t[i][j]==true) return false;
    }  

    return true;

}

void hetmany(bool t[8][8], short n){
    //hetmany(t, 0)
    //w pierwszym wywołaniu tablica t musi być wypełniona zerami
    //tablica t informuje o tym czy na danych polach stoją hetmany
    //n oznacza liczbę już ustawionych hetmanów
    //jednocześnie n oznacza liczbę wiersza, w którym dostawiamy hetmana

    if (n==8){
        for (int i=0; i<8;++i)
            for (int j=0; j<8;++j){
                if (t[i][j]){
                    cout<<"w: "<<i<<" k: "<<j<<"\t";
                }
            }
        cout<<endl; 
        return;    
    }

    for (int j=0; j<8;++j)
        if (moznaPostawic(t,n,j)){
            t[n][j]=true;
            hetmany(t, n+1);
            t[n][j]=false; //backtracking
        }
    
}

int main(){
    bool t[8][8]={0};
    hetmany(t,0);

    return 0;
}