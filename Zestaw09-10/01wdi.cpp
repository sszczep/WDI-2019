struct node {
    int w;
    node *next;
};

void insert(node *start, int n) {
    node *p = start;
    node *q = nullptr;
    while (p != nullptr and p->w < n) {
        q = p;
        p = p->next;
    }
    if (p != nullptr and p->w == n) {
        return;
    }

    node *nowy = new node;
    nowy->w = n;
    nowy->next = p;
    if (q != nullptr) {
        q->next = nowy;
    }
    else {
        start = nowy;
    }

}