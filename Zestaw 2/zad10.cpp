#include <iostream>
#include <cmath>

double f(double x){
	return 1/x;
}

int main(){
	double k;
	double dx;
	std::cout << "Podaj k: ";
	std::cin >> k;

	dx = k/2;

	double area = 0;
	while(dx > 1e-7){
		for(double i = 1; i < k; i+= dx){
			area += dx * f(i+dx);
		}
		dx /= 2;

		std::cout << "dX: " << dx << " => " << area << '\r' << std::flush;
		area = 0;
	}

	std::cout << std::endl;

	return 0;
}
