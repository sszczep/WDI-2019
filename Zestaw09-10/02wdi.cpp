struct node {
    int idx;
    int w;
    node *next;
};

int value(node *tab, int n) {
    while (tab != nullptr && tab->idx < n) {
        tab = tab->next;
    }
    if (tab == nullptr) {
        return 0;
    }
    return tab->idx == n ? tab->w : 0;
}