#include <iostream>
#define MAX 8

using namespace std;

pair<bool, pair<int,int>> f(int tab[MAX][MAX],int il){
    for (int bok=3;bok<=MAX;bok+=2)
        //x,y oznaczają wsp. górnego lewego roku kwadratu
        for (int x=0;x+bok-1<MAX; x++)
            for (int y=0;y+bok-1<MAX;y++)
                if (tab[x][y]*tab[x][y+bok-1]*tab[x+bok-1][y]*tab[x+bok-1][y+bok-1]==il)
                    return {true,{x+(bok-1)/2,y+(bok-1)/2}}; //zwracamy współrzędne środka kwadratu
    return {false,{-1,-1}};

}

int main(){
	int tab[MAX][MAX];
	srand(time(NULL));
			
	for (int i=0; i<MAX; ++i){
		for (int j=0; j<MAX; ++j){
			tab[i][j]=1+rand()%6;
			cout<<tab[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}

    cout<<f(tab,10).first<<" "<<f(tab,10).second.first<<" "<<f(tab,10).second.second;
    return 0;
}

#undef MAX
