#include <iostream>

struct node{
    node* next;
    int val;
}

//algorytm Floyda

int cycleLength(node* head){
    node *p, *q;
    p=q=head;
    while (true){
            p=p->next;
            q=q->next->next;
            if (p==q) break;
    }
    int cnt=0;
    while (true){
        p=p->next;
        cnt++;
        if (p==q) break;
    }
    return cnt;
}
