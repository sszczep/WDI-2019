#include <iostream>
using namespace std;

int main(){
	const int max=2000;
	int wynik[max], reszty[max], p, q;

	for (int i=0; i<max; i++){
		wynik[i]=reszty[i]=-1;
	}
	
	cin>>p>>q;
	cout<<p/q<<".";
	
	// Działamy, jak przy dzieleniu pisemnym

	int a=-1, b=-1;
	// indeksy początku i końca okresu, wartości -1 oznaczają że nie znaleźliśmy go (jeszcze)

	for (int i=0; i<max and a==-1; i++){
		p%=q;
		p*=10;

		wynik[i]=p/q;
		reszty[i]=p%q;
		
		//sprawdzamy, czy pojawił się okres
		for (int j=0; j<i; j++){
			if (reszty[i]==reszty[j] and wynik[i]==wynik[j]){
				a=j; b=i-1; break;
			}
		}
	}

	//wypisujemy wynik aż do ostatniej cyfry przed okresem
	for (int i=0; i<a; i++){
		cout<<wynik[i];
	}

	//jeżeli okresem jest (0) to znaczy, że nie ma okresu, więc już wypisaliśmy cały wynik
	if (wynik[a]==0 and a==b) return 0;

	//wypisujemy okres
	cout<<"(";
	for (;a<=b; a++)
	{
		cout<<wynik[a];
	}
	cout<<")";
	
	return 0;
}
