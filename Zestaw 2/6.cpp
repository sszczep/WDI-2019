#include <cmath>
#include <iostream>


// Liczba ma niepowtarzające się cyfry i nie zawiera 0 - ma maksymalnie 9 cyfr
// Reprezentujemy cyfry liczby ciągiem binarnym np. dana liczba 2137,
// to liczbę 13 reprezentujemy jako 0110.
// Najwieksza wartość zmiennej typu int to 2,147,483,647, więc 9 cyfr się mieści
// Zaczynamy od ciągu binarnego 0b0, a kończymy na 0b11111111-0x1FF


// Pobiera n-tą cyfrę od końca liczby
unsigned short digitAt(unsigned number, unsigned n){
	return (number/((unsigned)(pow(10,n-1))))%10;
}

int main(){
	unsigned number, snum;
	unsigned bits = 0, numlen = 0;
	std::cin >> number;
	snum = number;
	while(number > 0){
		numlen++;
		number /= 10;
		bits <<= 1;
		bits++;
	}

	for(unsigned bRep = 0x01; bRep <= bits; bRep++){
		// Konstrukcja liczby za pomocą ciągu binarnego
		unsigned resultnumber = 0;
		unsigned dCtr = 0;
		for(unsigned i = 0; i < numlen; i++){
			if((1 << i) & bRep){
				resultnumber += digitAt(snum, i+1) * pow(10, dCtr++);
			}
		}
		if(resultnumber % 7 == 0 && resultnumber)
			std::cout << "Istnieje liczba: " << resultnumber << " podzielna prez 7." << std::endl;
	}

}
