#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

using namespace std;

bool f(int tab[MAX]){
	bool onlyOneMax=true, onlyOneMin=true;
	int max,min;
	min=max=tab[0];
	
	for (int i=1; i<MAX; ++i){
		if (tab[i]==min){
			onlyOneMin=false;
		}
		else if (tab[i]<min){
			onlyOneMin=true;
			min=tab[i];
		}
		
		if (tab[i]==max){
			onlyOneMax=false;
		}
		else if (tab[i]>max){
			onlyOneMax=true;
			max=tab[i];
		}		
	}
	return onlyMin and onlyMax;
}

// do testowania
int main(){
	int tab[MAX]={0};
	srand(time(NULL));
	for (int i=0; i<MAX; ++i){
		tab[i]=rand()%10000-5000;
		cout<<tab[i]<<'\t';
	}
	cout<<f(tab);
}
