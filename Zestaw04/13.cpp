#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MAX 100

/* 13. Liczby naturalne a,b są komplementarne jeżeli ich suma jest liczbą pierwszą. Dana
jest tablica typu int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę
napisać funkcję, która zeruje elementy nie posiadające liczby komplementarnej.*/

using namespace std;

bool pierwsza (int n){
    if (n==0 or n==1) return false;
    else if (n==2) return true;
    else if (n%2==0) return false;
    for (int i=3; i*i<=n; i+=2){
        if (n%i==0) return false;
    }
    return true;
}

void f(int tab[MAX][MAX]){
    
    bool ma_komp[MAX][MAX]={0};
    
    for (int i=0;i<MAX*MAX-1;i++){
        for (int j=i+1;j<MAX*MAX;j++){
            if (pierwsza(tab[i/MAX][i%MAX]+tab[j/MAX][j%MAX])){
                ma_komp[i/MAX][i%MAX]=true;
                ma_komp[j/MAX][j%MAX]=true;
                //cout<<"komplementarne "<<tab[i/MAX][i%MAX]<<" i "<<tab[j/MAX][j%MAX]<<endl;
            
            }
        }
    }

    for (int i=0; i<MAX*MAX;++i){
        if (ma_komp[i/MAX][i%MAX]==false){
            tab[i/MAX][i%MAX]=0;
        }
    }

}


int main(){
	int tab[MAX][MAX];
	srand(time(NULL));
			
	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			tab[i][j]=1+rand()%100;
			cout<<tab[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}

    f(tab); cout<<"----------------------------------------------------------\n\n";

	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			cout<<tab[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}   
    return 0;
}

#undef MAX
