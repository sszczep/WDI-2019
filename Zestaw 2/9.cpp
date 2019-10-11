#include <iostream>

bool isFibSum(unsigned number){
	unsigned n1 = 1, n2 = 1;
	unsigned sum = 0;
	while(sum < number){
		sum += n1;
		n2 += n1;
		n1 = n2-n1;
	}

	if(sum == number)
		return true;

	n1 = 1; n2 = 1;
	while(sum > number){
		sum -= n1;
		n2 += n1;
		n1 = n2 - n1;
	}

	if(sum == number)
		return true;

	return false;
}

int main(){
	unsigned n;
	std::cin >> n;

	while(isFibSum(++n));

	std::cout << n << std::endl;
}
