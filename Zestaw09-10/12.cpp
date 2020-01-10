#include <iostream>

/* 12. Proszę napisać funkcję, która otrzymując jako parametr wskazujący na
początek listy jednokierunkowej, przenosi na początek listy te z nich,
które mają parzystą ilość piątek w zapisie ósemkowym.*/

/*Interpretuję to na tej zasadzie, że zachowujemy kolejność przenoszonych
elementów.*/

struct node{
    int val;
    node* next;
}

bool toMove(node* item){
    n=item->val;
    int cnt5=0;
    while (n>0){
        if(n%8==5) cnt5++;
        n/=8;
    }
    return ((cnt5%2)==0);
}

void move_rek(node* &subTail, node* item, node* prev){
    if (item==NULL) return;
    if (toMove(item)){
        prev->next=item->next;
        item->next=subTail->next;
        subTail->next=item;
        subTail=item;
        move_rek(subTail,prev->next,prev);
    }
    else{
        move_rek(subTail, item->next, item);
    }
}

void moveToHead (node* &head){

    node* subTail;
    // subTail - ogon przeniesionej części, jako jego nexty
    // będziemy przenosić kolejne node'y

    if (toMove(head)){
        subTail=head;
        node *prev;
        while (subTail!=NULL and toMove(subTail)){
            prev=subTail;
            subTail=subTail->next;
        }
        subTail=prev;
    }

    //jeżeli na początku listy nie stoi element, dla którego toMove
    //zwróciłoby true, to szukamy pierwszego takiego elementu,
    //przenosimy go na początek i ustawiamy go jako nowego heada

    node *item, *prev;

    if (subTail=NULL){
        item=head->next;
        prev=head;
        while (item!=NULL){
            if (toMove(item)){
                prev->next=item->next;
                item->next=head;
                head=subTail=item;
                break;
            }
            prev=item;
            item=item->next;
        }
        if(item==NULL) return;
    }
    //rekurencyjnie znajdujemy i przenosimy resztę
    move_rek(subTail,subTail->next,subTail);
}
