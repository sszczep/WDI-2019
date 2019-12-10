#include <iostream>
using namespace std;

struct node {
    int index;
    int value;
    node *next = nullptr;
};

void init(node *&tab) {
    tab = nullptr;
}

//jak mam zwrocic wartosc o indeksie n, jak moze nie byc indeksu n? dr gajecki pls
bool value(node *tab, int &result, int index) {
    while (tab) {
        if (tab->index == index) {
            result = tab->value;
            return true;
        }
        tab = tab->next;
    }
    return false;
}

void set(node *&tab, int index, int value) {
    node *curr = tab;
    while (curr) {
        if (curr->index == index) {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }
    node *added = new node;
    added->index = index;
    added->value = value;
    added->next = tab;
    tab = added;
}