#include <iostream>
#include <vector>

using namespace std;

int number;
int base;

vector<char> digits;

char getCharForDigit(int num) {
    return (num > 9) ? ('a' + (num % 10)) : ('0' + num);
}

int main() {
    cin >> number;
    cin >> base;

    if (base < 2 || base > 16) {
        cout << "base ma sie zawierac w [2,16]";
        return 0;
    }

    while (number > 0) {
        digits.push_back(getCharForDigit(number % base));
        number /= base;
    }

    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i];
    }

}