#include <iostream>
#include <random>
#include <cmath>

using namespace std;

default_random_engine engine;

double integrate(double (*fun)(double), double minX, double maxX, double minY, double maxY, long long iter) {
    uniform_real_distribution<double> genX(minX, maxX);
    uniform_real_distribution<double> genY(minY, maxY);

    double area = abs(maxX - minX) * abs(maxY - minY);

    long long fitting = 0;
    for (long long i = 0; i < iter; i++) {
        double x = genX(engine);
        double y = genY(engine);
        double calcY = fun(x);

        if ((calcY > 0 && y > 0 && y < calcY)) {
            fitting++;
        }

        if ((calcY < 0 && y < 0 && y > calcY)) {
            fitting--;
        }
    }

    double percentage = ((double)fitting) / iter;
    return area * percentage;
}

double Y1(double x) {
    return x*x*x;
}

double Y2(double x) {
    return x*x;
}

double Y3(double x) {
    if (x < 0) {
        return Y1(x);
    }
    else {
        return Y2(x);
    }
}

int main() {
    double xp;
    double xk;
    long long iterations;
    cin >> xp;
    cin >> xk;
    cin >> iterations;
    cout << integrate(Y1, xp, 0 , Y1(xp), 0     , iterations) << endl;
    cout << integrate(Y2, 0 , xk, 0     , Y2(xk), iterations) << endl;
    cout << integrate(Y3, xp, xk, Y3(xp), Y3(xk), iterations);
}