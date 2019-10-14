#include <iostream>
#include <cmath>

unsigned rightmostDigit(unsigned n){
	while(n % 10 == 0)
		n /= 10;
	return n % 10;
}

unsigned manualFactorial(unsigned n){
	unsigned s = 1;
	for(unsigned i = 1; i <= n; i++) s *= i;
	return s;
}

unsigned pow2nlastdigit(unsigned n){
	if(n % 4 == 1) return 2;
	if(n % 4 == 2) return 4;
	if(n % 4 == 3) return 8;
	if(n % 4 == 0) return 6;
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
		return rightmostDigit(pow2nlastdigit(integer) *  D(integer) * manualFactorial(remainder));
	}
}

int main(){
	unsigned n;
	std::cin >> n;

	std::cout << "Ostatnia niezerowa cyfra to: " << D(n)  << std::endl;

}
