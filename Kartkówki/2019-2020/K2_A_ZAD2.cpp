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

int func(int x, int y, int n) {
    if(x == y) return 1;
    if(x > y || n == 0) return 0;

    n--;

    return func(A(x), y, n) + func(B(x), y, n) + func(C(x), y, n);
}

int main() {
    std::cout << func(11, 33, 4);
}
