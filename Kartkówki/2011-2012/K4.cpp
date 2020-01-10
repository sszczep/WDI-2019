#include <iostream>
using namespace std;

struct node {
    int32_t val;
    node *next;
};

enum bits {
    low,
    med,
    high
};

bits getBits(int32_t num) {
    uint32_t mask = 0x01;
    int result = 0;

    for (int i = 0; i < 32; i++) {
        if (num & mask) {
            result++;
        }
        mask <<= 1;
    }

    if (result < 8) {
        return low;
    }
    if (result < 25) {
        return med;
    }
    return high;
}

void append(node *&first, node *&last, node *toAdd) {
    if (last) {
        last->next = toAdd;
    }
    else {
        first = toAdd;
    }
    last = toAdd;
}

void przetworz(node *&list) {
    node *lowFirst = nullptr;
    node *lowLast = nullptr;
    node *medFirst = nullptr;
    node *medLast = nullptr;
    node *highFirst = nullptr;
    node *highLast = nullptr;

    while (list) {
        bits bits = getBits(list->val);
        node *next = list->next;

        if (bits == low) {
            append(lowFirst, lowLast, list);
        }
        else if (bits == med) {
            append(medFirst, medLast, list);
        }
        else {
            append(highFirst, highLast, list);
        }
        
        list = next;
    }

    lowLast->next = nullptr;
    medLast->next = nullptr;
    highLast->next = nullptr;

    list = highFirst;
    if (medFirst) {
        medLast->next = list;
        list = medFirst;
    }
    if (lowFirst) {
        lowLast->next = list;
        list = lowFirst;
    }
}