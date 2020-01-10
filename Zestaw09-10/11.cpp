#include <iostream>

/* 11. Proszę napisać funkcję, która otrzymując jako parametr
wskaźnik wskazujący na początek listy jednokierunkowej, usuwa z niej wszystkie elementy,
w których wartość klucza w zapisie trójkowym ma większą ilość jedynek niż dwójek.*/

struct node{
    int val;
    node* next;
}

bool toRemove(node *item){
    n=item->val;
    int cnt2=0, cnt1=0;
    while (n>0){
        switch (n%3)
        {
        case 1: cnt1++; break;
        case 2: cnt2++; break;
        }
        n/=3;
    }
    return (cnt1>cnt2);
}  

void remove_rek(node* item, node* prev){
    if (item==NULL) return;
    else if (toRemove(item)){
        else{
            prev->next=item->next;
            delete item;
            remove_rek(prev->next,prev);
        }
    }
    else{
        remove_rek(item->next,item);
    }
}

void removeBadItems(node* &head){
    //usuwamy wszystkie złe elementy z początku listy, aż natrafimy na pierwszy dobry,
    //który będzie nowym headem
    while(head!=NULL and toRemove(head)){
        node* next=head->next;
        delete head;
        head=next;
    }
    //rekurencyjnie usuwamy złe elementy wewnątrz listy
    if (head != NULL and head->next != NULL)
        remove_rek(head->next,head);
}
