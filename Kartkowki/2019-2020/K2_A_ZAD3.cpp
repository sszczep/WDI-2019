#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

int remove(node *&list) {
    node *mSubPrev; //wskaznik przed poczatkiem kawalka do wyciecia
    int mSubLength = 0;
    bool mSubTwice = true; //flaga na sytuacje, gdy mamy >= 2 kawalki maksymalne tej samej dlugosci

    node *listCopy = list;
    node *prev = nullptr;

    while (listCopy != nullptr) {
        if (listCopy->next != nullptr and listCopy->val == listCopy->next->val) {
            node *subPrev = prev;
            int subLength = 2;
            listCopy = listCopy->next;

            while (listCopy->next != nullptr and listCopy->next->val == listCopy->val) {
                subLength++;
                listCopy = listCopy->next;
            }

            if (subLength == mSubLength) {
                mSubTwice = true;
            }

            if (subLength > mSubLength) {
                mSubPrev = subPrev;
                mSubLength = subLength;
                mSubTwice = false;
            }
        }
        prev = listCopy;
        listCopy = listCopy->next;
    }

    if (!mSubTwice) {
        node *mSubToDel = mSubPrev == nullptr ? list : mSubPrev->next;

        for (int i = 0; i < mSubLength - 1; i++) {
            node *next = mSubToDel->next;
            delete mSubToDel;
            mSubToDel = next;
        }

        if (mSubPrev == nullptr) {
            list = mSubToDel->next;
        }
        else {
            mSubPrev->next = mSubToDel->next;
        }
        delete mSubToDel;
        
        return mSubLength;
    }
    else {
        return 0;
    }
}

//***********************************************************************
//***************************KOD DO TESTOWANIA***************************
//***********************************************************************

void wypisz(node *list) {
    if (list == nullptr) {
        return;
    }
    cout << list->val;
    list = list->next;
    while (list != nullptr) {
        cout << "->" << list->val;
        list = list->next;
    }
    cout << endl;
}

node *buildList(int values[], int size) {
    node *result = nullptr;
    for (int i = size - 1; i >= 0; i--) {
        node *toAdd = new node;
        toAdd->val = values[i];
        toAdd->next = result;
        result = toAdd;
    }
    return result;
}

void test(node *list) {
    wypisz(list);
    cout << remove(list) << endl;
    wypisz(list);
    cout << endl;
}

int main() {
    wypisz(nullptr);
    int A[] = {1, 1, 1, 1};
    node *listA = buildList(A, 4);
    test(listA);

    int B[] = {1, 2, 3, 4, 5};
    node *listB = buildList(B, 5);
    test(listB);

    int C[] = {1, 1, 1, 1, 2, 3, 3};
    node *listC = buildList(C, 7);
    test(listC);

    int D[] = {4, 5, 5, 5, 5, 6, 6};
    node *listD = buildList(D, 7);
    test(listD);

    int E[] = {7, 8, 8, 9, 9, 9, 9};
    node *listE = buildList(E, 7);
    test(listE);

    int F[] = {10, 10, 10, 11, 11, 12, 12, 12};
    node *listF = buildList(F, 8);
    test(listF);
}