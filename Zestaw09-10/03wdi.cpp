struct node {
    int val;
    node *next;
};

node *merge(node *l1, node *l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    node *res, *p;
    if (l1->val < l2->val) {
        res = l1;
        l1 = l1->next;
    }
    else {
        res = l2;
        l2 = l2->next;
    }
    p = res;
    while (l1 != nullptr and l2 != nullptr) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1 != nullptr) {
        p->next = l1;
    }
    else {
        p->next = l2;
    }
    return res;
}

node *mergeR(node *l1, node *l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    if (l1->val > l2->val) {
        l2->next = merge(l1, l2->next);
        return l2;
    }
    else {
        l1->next = merge(l1->next, l2);
        return l1;
    }
}