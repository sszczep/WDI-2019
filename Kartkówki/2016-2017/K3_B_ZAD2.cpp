#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

int split(node *a, node *b) {
    if (b == nullptr) {
        return 0;
    }

    while (a != nullptr) {
        node *bTmp = b;
        node *bTmpPrev = nullptr;

        while (bTmp != nullptr) {
            if (bTmp == a) {
                int added = 0;
                while (a != nullptr) {
                    bTmpPrev->next = new node;
                    bTmpPrev->next->val = a->val;
                    bTmpPrev = bTmpPrev->next;
                    a = a->next;
                    added++;
                }
                bTmpPrev->next = nullptr;
                return added;
            }
            bTmpPrev = bTmp;
            bTmp = bTmp->next;
        }
        a = a->next;
    }
    return 0;
}

void wypisz(node *list) {
    if (list == nullptr) {
        return;
    }
    cout << list->val << '(' << list << ')';
    list = list->next;
    while (list != nullptr) {
        cout << "->" << list->val << '(' << list << ')';
        list = list->next;
    }
    cout << endl;
}

int main() {
    node *a = new node;
    a->next = nullptr;
    a->val = 3;
    node *b = new node;
    b->next = a;
    b->val = 2;
    node *c = new node;
    c->next = b;
    c->val = 1;
    node *d = new node;
    d->next = b;
    d->val = 10;
    wypisz(c);
    wypisz(d);
    cout << split(c, d) << endl;
    wypisz(c);
    wypisz(d);

}