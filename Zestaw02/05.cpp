#include <iostream>
#include <cmath>

unsigned rightmostDigit(unsigned n){
	while(n % 10 == 0)
		n /= 10;
	return n % 10;
}

unsigned D(unsigned n){
	if(n < 7){
		unsigned s = 1; 
		for(unsigned i = 1; i <= n; i++) s *= i;
		return rightmostDigit(s);
	}
	else{
		unsigned integer = n / 5;
		unsigned remainder = n % 5;
		return rightmostDigit(pow(2,integer) *  D(integer) * D(remainder));
	}
}

int main(){
	unsigned n;
	std::cin >> n;

	std::cout << "Ostatnia niezerowa cyfra to: " << D(n)  << std::endl;

}
