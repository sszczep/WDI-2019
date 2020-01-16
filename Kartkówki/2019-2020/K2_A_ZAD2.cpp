#include <iostream>

int A(int x) {
    return x + 3;
}

int B(int x) {
    return x * 2;
}

int C(int x) {
    int mult = 1, result = 0;
    while(x != 0) {
        int digit = x % 10;
        if(x % 2 == 0) digit++;
        result += digit * mult;
        x /= 10;
        mult *= 10;
    }
    return result;
}

int func(int x, int y, int n, char c = '-') {
    if(x == y) return 1;
    if(x > y || n == 0) return 0;

    n--;

    return 
          ( c != 'A' ? func(A(x), y, n, 'A') : 0)
        + ( c != 'B' ? func(B(x), y, n, 'B') : 0) 
        + ( c != 'C' ? func(C(x), y, n, 'C') : 0);
}

int main() {
    std::cout << func(11, 33, 4);
}
