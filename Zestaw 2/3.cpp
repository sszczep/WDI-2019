#include <iostream>

int main() {
	unsigned num, rnum = 0, snum;
	std::cin >> num;
	snum = num;
	
	while(num > 0) {
		rnum = (rnum * 10) + (num % 10);
		num /= 10;
	}

	if(rnum == snum)
		std::cout << "Liczba jest palindromem dziesiątkowo." << std::endl;

	num = snum; 
	rnum = 0;

	while(num > 0) {
		rnum = (rnum * 2) + (num % 2);
		num /= 2;
	}

	if(snum == rnum)
		std::cout << "Liczba jest palindromem dwójkowo." << std::endl;
}
