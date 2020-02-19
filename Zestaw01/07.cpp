#include <iostream>

using namespace std;

int main(){
	int n;
	
	cin>>n;
	
	int a=0, b=1;
	
	while (a<n){
		if (a*b==n){
			cout<<"Tak, te liczby to a="<<a<<" i b="<<b;
			return 0;
		}
		
		a+=b;
		int tmp=a;
		a=b;
		b=tmp;
	}
	
	
	cout<<"Nie";
	
	return 0;
}
