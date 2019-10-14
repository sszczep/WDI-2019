#include <iostream>
#include <cmath>

int main(){
	unsigned num, i;
	std::cin >> num;
	for(i = sqrt(num); i >= 1 && num % i != 0; i++);

	std::cout << num << " = " << i << "*" << num/i << std::endl;
}
