#include <iostream>
using namespace std;

struct node {
    int val;
    node *next = nullptr;
};

struct node_set {
    node *first[10];
    node *last[10];
};

void append(node *&last, node *toAdd) {
    if (last) {
        last->next = toAdd;
    }
    last = toAdd;
}

node_set split(node *nodes) {
    node_set res;
    for (int i = 0; i < 10; i++) {
        res.first[i] = nullptr;
        res.last[i] = nullptr;
    }
    while (nodes) {
        int idx = nodes->val % 10;
        append(res.last[idx], nodes);

        if (!res.first[idx]) {
            res.first[idx] = res.last[idx];
        }
        nodes = nodes->next;
    }
    for (int i = 0; i < 10; i++) {
        if (res.last[i]) {
            res.last[i]->next = nullptr;
        }
    }
    return res;
}

node *merge(node_set nodeSet) {
    node *res = nullptr;
    node *last;
    for (int i = 0; i < 10; i++) {
        if (nodeSet.first[i]) {
            if (res) {
                last->next = nodeSet.first[i];
            }
            else {
                res = nodeSet.first[i];
            }
            last = nodeSet.last[i];
        }
    }
    return res;
}

node *split_and_merge(node *nodes) {
    return merge(split(nodes));
}

//PONIZEJ KOD TYLKO DO TESTOWANIA

void wypisz(node *nodes) {
    while (nodes) {
        cout << nodes->val << "->";
        nodes = nodes->next;
    }
    cout << endl;
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

    wypisz(split_and_merge(l));
}