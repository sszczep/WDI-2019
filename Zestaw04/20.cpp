#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX 5

using namespace std;

/*20. Dana jest tablica t[N][N] (reprezentująca szachownicę) wypełniona liczbami
naturalnymi. Proszę napisać funkcję która ustawia na szachownicy dwie wieże, tak
aby suma liczb na „szachowanych” przez wieże polach była największa. Do funkcji
należy przekazać tablicę, funkcja powinna zwrócić położenie wież. Uwaga: zakładamy,
że wieża szachuje cały wiersz i kolumnę z wyłączeniem pola na którym stoi*/


//zwraca sumę liczb na polach szachowanych przez wieżę
int ileSzachuje (int tab[MAX][MAX], int w, int k){
    int sum=0;
    for (int i=0; i<MAX; i++){
        sum+=tab[w][i];
        sum+=tab[i][k];
    }
    sum-=(2*tab[w][k]);
    return sum;
}

pair<pair<int, int>,pair<int,int>> f(int tab[MAX][MAX]){
    
    pair <int,int> wieza1={0,0}, wieza2={0,0};
    
    int suma1=0;
    int suma2=0;
    
    for (int i=0; i<MAX;i++){
    
        for (int j=0; j<MAX;j++){
    
            if (ileSzachuje(tab, i, j) > suma1){
                wieza2=wieza1;
                suma2=suma1;

                wieza1.first=i;
                wieza1.second=j;
                suma1=ileSzachuje(tab,i,j);
            }

            else if (ileSzachuje(tab, i, j)>suma2){
                wieza2.first=i;
                wieza2.second=j;
                suma2=ileSzachuje(tab,i,j);
            }

        }
    }
    return {wieza1, wieza2};
}

int main(){
	int tab[MAX][MAX];
	srand(time(NULL));
			
	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			tab[i][j]=rand()%1000;
			cout<<tab[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}
	cout<<"("<<f(tab).first.first<<", "<<f(tab).first.second<<"), "
        <<"("<<f(tab).second.first<<", "<<f(tab).second.second<<")";
	
	return 0;
}


#undef MAX
