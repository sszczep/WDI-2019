#include <iostream>
#include <cstdlib>
#include <time.h>
#include <limits.h>
#define MAX 4

using namespace std;

void move(int t1[MAX][MAX],int t2[MAX*MAX]){
	for (int i=0; i<MAX*MAX;++i)
		t2[i]=0;

	int ind1[MAX]={0};
	//ind1[i] - indeks pierwszego nieprzeniesionego elementu z wiersza t1[i][]
	int moved=0;//ilość unikalnych elementów przeniesionych do t2

	while (true){
		int ix_min, min=INT_MAX;
		bool foundMin=false;

		//znajdujemy wiersz t1[i][], w którym jest najmniejsza wartość do przeniesienia
		for (int i=0; i<MAX; ++i){
			if (ind1[i]==MAX) continue; // z wiersza t1[i][] przenieśliśmy już wszystko 
			
			if (t1[i][ind1[i]]<min){
				ix_min=i;
				min=t1[i][ind1[i]];
				foundMin=true;
			}
		}

		if (foundMin==false) return;
		// nie znaleźliśmy najmniejszej wartości do przeniesienia
		// to znaczy, że przenieśliśmy już wszystko z całej t1

		if (moved==0){
			t2[0]=t1[ix_min][0];
			ind1[ix_min]++;
			moved++;
		}

		//jeśli danej wartości jeszcze nie ma w t2 to ją przenosimy
		else if (min>t2[moved-1]){
			t2[moved]=min;
			ind1[ix_min]++;	
			moved++;
		}
		//jeśli dana wartość już jest w t2 to sygnalizujemy, że jest przeniesiona też z t[ix_min][]
		else{
			ind1[ix_min]++;				
		}
	}
}

//do testowania
int main(){
	int t1[MAX][MAX];int t2[MAX*MAX];

	srand(time(NULL));
	for (int i = 0;i<MAX;++i){
		t1[i][0]=(rand()%MAX)+1;
		for (int j=1; j<MAX; ++j){
			t1[i][j]=t1[i][j-1]+(rand()%MAX)+1;
		}
	}
	
	for (int i=0; i<MAX;++i){
		for (int j=0; j<MAX; ++j){
			cout<<t1[i][j]<<'\t';
		}
		cout<<endl;
	}
	cout<<endl;
	move(t1,t2);
	
	for (int i=0; i<MAX*MAX; i++) cout<<t2[i]<<" ";
	
	return 0;
}


