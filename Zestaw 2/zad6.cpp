#include <cmath>
#include <iostream>


//liczba ma niepowtarzajace sie cyfry, i nie zawiera 0 - ma maksymalnie 9 cyfr
//reprezentujemy cyfry liczby ciagiem binarnym np. dana liczba 2137,
//to liczbe 13 reprezentujemy jako 0110.
//najwiekza wartosc zmiennej typu int to 2,147,483,647, wiec 9 cyfr sie miesci
//zaczynamy od ciagu binarnego 0b0, a konczymy na 0b11111111-0x1FF


//pobiera n-ta cyfre od konca liczby
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
		//konstrukcja liczby za pomoca ciagu binarnego
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
