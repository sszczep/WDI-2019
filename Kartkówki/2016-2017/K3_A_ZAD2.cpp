struct node {
    int val;
    node *next;
};

int uniq(node *&a, node *&b) {
    if (a == nullptr || b == nullptr) {
        return 0;
    }
    while (a->next->val > a->val) {
        a = a->next;
    }
    while (b->next->val > b->val) {
        b = b->next;
    }
    node *aPrev = a;
    node *bPrev = b;
    a = a->next;
    b = b->next;
    node *aStart = a;
    node *bStart = b;

    int result = 0;
    do {
        if (a->val == b->val) {
            if (a->next == a) {
                delete a;
                a = nullptr;
            }
            else {
                aPrev->next = a->next;
                delete a;
            }
            if (b->next == b) {
                delete b;
                b = nullptr;
            }
            else {
                bPrev->next = b->next;
                delete b;
            }
            result += 2;
            a = aPrev->next;
            b = bPrev->next;
        }
        else {
            if (a->val > b->val) {
                bPrev = b;
                b = b->next;
            }
            else {
                aPrev = a;
                a = a->next;
            }
        }
    }
    while (a != aStart and b != bStart and a != nullptr and b != nullptr);

    return result;
}