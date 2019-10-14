#include <iostream>
#include <cmath>

//liczba n jest liczba fibonnaciego w.t.w. gdy 
//5x^2+4 lub 5x^2-4 sa kwadratem liczby naturalnej
//https://en.wikipedia.org/wiki/Fibonacci_number#Identification

bool isSquare(unsigned number){
	unsigned s = sqrt(number);
	return s * s == number;
}

bool isFib(unsigned number){
	return isSquare(5*number*number+5) || isSquare(5*number*number-4);	
}

int main(){
	unsigned liczba;
	std::cin >> liczba;
	unsigned n1 = 2, n2 = 3; //pomijamy jedynki w ciagu fib.

	while(n1 < sqrt(liczba)){
		if(liczba % n1 == 0 && liczba % (liczba / n1) == 0 && isFib(liczba / n1))
			std::cout << "Liczba to iloczyn: " << n1 << " i " << liczba / n1 << std::endl;
		n2 += n1;
		n1 = n2 - n1;
	}

	return 0;
}
