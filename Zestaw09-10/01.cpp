#include <iostream>
using namespace std;

struct node {
    int value;
    node *next = nullptr;
};

bool contains(node *haystack, int needle) {
    while (haystack) {
        if (haystack->value == needle) {
            return true;
        }
        haystack = haystack->next;
    }
    return false;
}

bool add(node *&first, int value) {
    if (contains(first, value)) {
        return false;
    }
    node *added = new node;
    added->value = value;
    added->next = first;
    first = added;
    return true;
}

bool remove(node *&first, int value) {
    if (!first) {
        return false;
    }
    node *prev = nullptr;
    node *curr = first;
    do {
        if (curr->value == value) {
            if (prev) {
                prev->next = curr->next;
                delete curr;
            }
            else {
                node *to_delete = first;
                first = first->next;
                delete to_delete;
            }
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    while (curr);
    return false;
}

void wypisz(node *zbior) {
    while (zbior) {
        cout << zbior->value << endl;
        zbior = zbior->next;
    }
}

//funkcja testujaca
int main() {
    node *zbior = nullptr;
    while (true) {
        char key;
        int val;
        cin >> key;
        cin >> val;
        switch (key) {
            case 'c':
                cout << (contains(zbior, val) ? 't' : 'f') << endl;
                break;
            case 'a':
                cout << (add(zbior, val) ? 't' : 'f') << endl;
                break;
            case 'r':
                cout << (remove(zbior, val) ? 't' : 'f') << endl;
                break;
        }
        
        wypisz(zbior);
    }
}