struct node {
    int value;
    node *next = nullptr;
};

void append(node *toAdd, node *&last) {
    if (last) {
        last->next = toAdd;
    }
    last = toAdd;
}

node *scalIter(node *l, node *r) {
    node *result = nullptr;
    node *last = nullptr;
    while (l or r) {
        if (!r or (l and l->value >= r->value)) {
            append(l, last);
            l = l->next;
        }
        else {
            append(r, last);
            r = r->next;
        }
        if (!result) {
            result = last;
        }
    }
    return result;
}