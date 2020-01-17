#include <cmath>
#include <iostream>

using namespace std;

struct punkt {
    int x;
    int y;
};

struct srodek {
    double x;
    double y;
};

const int MAX = 10;
const int POW = 1 << MAX;

punkt tab[MAX];

srodek srodki[POW - 1];

//int zapisane = 0;
//int minD;
//podzbiory(0, 0, 0, 0, zapisane, minD)
void podzbiory(int i, int s, int sX, int sY, int& zapisane, double& minD) {
    if (i == MAX) {
        if (s > 0) {
            srodek sr;
            sr.x = sX / s;
            sr.y = sY / s;
            srodki[zapisane] = sr;
            for (int a = zapisane - 1; a >= 0; a--) {
                double d = pow(sr.x - srodki[a].x, 2) + pow(sr.y - srodki[a].y, 2);
                if (d < minD || zapisane == 0) {
                    minD = d;
                }
            }
            zapisane++;
        }
    }
    else {
        podzbiory(i + 1, s, sX, sY, zapisane, minD);
        podzbiory(i + 1, s + 1, sX + tab[i].x, sY + tab[i].y, zapisane, minD);
    }
}