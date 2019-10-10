#include <iostream>
#include <cmath>

//A(n) = n*n + n + 1

unsigned An(unsigned n){
	return n*n + n + 1;
}

int main(){
	unsigned n, an;
	std::cin >> n;	
	bool result = false;
	
	for(unsigned i = 1; (an = An(i)) <= n; i++){
		std::cout << an << std::endl;
		if(n % an == 0)
			result = true;
	}
	
	if(result)
		std::cout << "Jest " << std::endl;
	else
		std::cout << "Nie jest " << std::endl;

}
