struct node {
    int idx;
    int w;
    node *next;
};

int del(node *&f) {
    int licz = 0;
    node *war = new node;
    war->next = f;
    f = war;

    node *p = f->next;
    node *r = f;

    while (p != nullptr and p->next != nullptr) {
        if (p->w == p->next->w) {
            int x = p->w;
            node *q = p->next;
            while (q != nullptr and q->w == x) {
                p->next == q->next;
                delete q;
                q = p->next;
            }
            r->next = q;
            delete p;
            p = q;
        }
        else {
            r = p;
            p = p->next;
        }
    }
}