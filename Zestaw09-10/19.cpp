#include <iostream>

struct node{
    node* next;
    int val;
};

//algorytm Floyda

bool hasCycle(node* head){
    if (head==NULL) return false;
    node *p=head, *q=head;

    while (q->next!=NULL and q->next->next!=NULL)
            p=p->next;
            q=q->next->next;
            if (p==q) return true;
    }
    return false;
}
