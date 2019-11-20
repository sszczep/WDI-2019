#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX 5

using namespace std;

/*19. Dana jest tablica wypełniona liczbami naturalnymi int t[MAX][MAX];
Proszę napisać funkcję, która zwraca liczbę par elementów, o określonym
iloczynie, takich że elementy są odległe o jeden ruch skoczka szachowego.*/




int f(int tab[MAX][MAX], int iloczyn){
    int cnt=0;

    /*sprawdzamy taki wzór:

        X

          X

    */

    for (int i=0; i<MAX-2;i++) // i - numer wiersza górnego pola
        for (int j=0; j<MAX-1; j++) // j - numer kolumny órnego pola
            if (tab[i][j]*tab[i+2][j+1]==iloczyn) cnt++;

    /*sprawdzamy taki wzór:

          X

        X

    */  

    for (int i=0; i<MAX-2;i++) // i - numer wiersza górnego pola
        for (int j=0; j<MAX-1; j++) // j - numer kolumny dolnego pola
            if (tab[i][j+1]*tab[i+2][j]==iloczyn) cnt++;

    /*sprawdzamy taki wzór:

             X
        X

    */  

    for (int i=0; i<MAX-1;i++) // i - numer wiersza górnego pola
        for (int j=0; j<MAX-2; j++) // j - numer kolumny dolnego pola
            if (tab[i][j+2]*tab[i+1][j]==iloczyn) cnt++;

    /*sprawdzamy taki wzór:

        X
             X

    */ 

    for (int i=0; i<MAX-1;i++) // i - numer wiersza górnego pola
        for (int j=0; j<MAX-2; j++) // j - numer kolumny górnego pola
            if (tab[i][j]*tab[i+1][j+2]==iloczyn) cnt++;

    return cnt;

}



int main(){
	int tab[MAX][MAX];
	srand(time(NULL));
			
	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			tab[i][j]=rand()%100;
			cout<<tab[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}
    cout<<f(tab, 10);
	return 0;
}


#undef MAX
