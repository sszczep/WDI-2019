#include <iostream>
#include <vector>

using namespace std;

vector<int> podsumy;

int a = 1;
int b = 1;
int c;

int szukana;
int main() {
    cin >> szukana;

    while (a < szukana) {
        podsumy.push_back(a);
        for (int i = 1; i < podsumy.size(); i++) {
            int nowa_podsuma = podsumy[i - 1] + a;
            if (nowa_podsuma == szukana) {
                cout << "istnieje" << endl;
                return 0;
            }
            podsumy[i - 1] = nowa_podsuma;
        }
        c = a+b;
        a = b;
        b = c;
    }

    cout << "nie istnieje" << endl;
}