#include <iostream>
#include <cmath>
#include <sstream>

std::string intToString(unsigned i){
	std::stringstream s;
	s << i;
	return s.str();
}

int main(){
	unsigned a, b, n, remainder;
	std::cout << "Podaj a : "; std::cin >> a;
	std::cout << "Podaj b : "; std::cin >> b;
	std::cout << "Podaj n : "; std::cin >> n;

	std::string result = intToString(a/b);

	result += ".";

	while(n--){
		a = (a % b) * 10;		
		result += (a / b) + '0';
	}

	std::cout << result << std::endl;

	return 0;	
}
