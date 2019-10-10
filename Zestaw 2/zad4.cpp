#include <cmath>
#include <iostream>

int main(){
	unsigned n, l = 0;
	std::cin >> n;
	for(unsigned i2 = 1; i2 <= n; i2 *= 2){
		for(unsigned i3 = i2; i3 <= n; i3 *= 3){
			l += floor(log(n/i3)/log(5))+1;
		}
	}

	std::cout << "W przedziale <1, n> jest " << l << " takich liczb. " << std::endl;
}
