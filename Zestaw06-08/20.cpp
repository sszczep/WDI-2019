#include <iostream>
using namespace std;

/*20. Tablica int t[8][8] zawiera liczby naturalne. Proszę napisać funkcję, która
sprawdza czy można wybrać z tablicy niepusty podzbiór o zadanej sumie. Warunkiem
dodatkowym jest aby żadne dwa wybrane elementy nie leżały w tej samej kolumnie ani
wierszu. Do funkcji należy przekazać wyłącznie tablicę oraz wartość sumy, funkcja
powinna zwrócić wartość typu bool.*/

bool f(int t[8][8], bool w[8], bool k[8], int n, int sum){
    //f(t,w,k,0,200)
    //w[i], k[i] - wskazują czy wybraliśmy już element z i-tego wiersza/kolumny
    if (sum==0 and n>0) return true;
    else if (n==8) return false;
    else if (sum<0) return false;

    for (int i=0;i<8;++i)
        for (int j=0; j<8;++j){
            if (w[i]==false and k[j]==false){
                w[i]=true; k[j]=true;
                if (f(t,w,k,n+1,sum-t[i][j])==true) return true;
                w[i]=false; k[j]=false; //backtracking
            }
        }
    return false;
}

bool Istnieje(int t[8][8], int sum){
    bool w[8],k[8];
    for (int i=0; i<8;++i) w[i]=k[i]=false;     
    return f(t,w,k,0,sum);
}

//do testowania
int main(){
	int tab[8][8];
	srand(time(NULL));
			
	for (int i=0; i<8; ++i){
		for (int j=0; j<8; ++j){
			tab[i][j]=1+rand()%50;
			cout<<tab[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}
    cout<<Istnieje(tab, 100);
    return 0;
}