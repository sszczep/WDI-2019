#include <iostream>
using namespace std;

struct node {
    int val;
    node *next = nullptr;
};

node *reverse(node *nodes) {
    node *nFront = nullptr;
    while (nodes) {
        node *rest = nodes->next;
        nodes->next = nFront;
        nFront = nodes;
        nodes = rest;
    }
    return nFront;
}

//PONIZEJ KOD TYLKO DO TESTOWANIA

void wypisz(node *nodes) {
    while (nodes) {
        cout << nodes->val << "->";
        nodes = nodes->next;
    }
    cout << endl;
}

void append(node *&last, node *toAdd) {
    if (last) {
        last->next = toAdd;
    }
    last = toAdd;
}

//wartosci nalezy podawac w kolejnosci rosnacej
int main() {
    node *l = nullptr;
    node *lLast = nullptr;

    int val;
    cin >> val;
    while (val != 0) {
        node *toAdd = new node;
        toAdd->val = val;
        append(lLast, toAdd);
        if (!l) {
            l = lLast;
        }
        cin >> val;
    }

    wypisz(reverse(l));
}