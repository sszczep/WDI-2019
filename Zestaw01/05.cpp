//
// Created by Bartłomiej Grzesik on 24/10/2019.
//

#include <iostream>
#include <cmath>

// 5. Napisać program wyznaczający pierwiastek kwadratowy ze wzoru Newtona.


int main()
{
    const double e = 0.0001;
    const double n = 103;

    double a = 1;
    double b = n / a;

    while (fabs(a * a - n) > e) {
        a = (a + b) / 2;
        b = n / a;
    }
    std::cout << a << std::endl;
}
