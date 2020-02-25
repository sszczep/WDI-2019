#include <iostream>
#include <string>
using namespace std;

/*
29. Napis s1 poprzedza napis s2 jeżeli ostatnia litera s1 jest „mniejsza”
od pierwszej litery s2. Według tej zasady rozmieszczono napisy w liście
cyklicznej, na przykład:
┌─bartek──leszek──marek──ola──zosia─┐
└───────────────────────────────────┘
Proszę napisać stosowne definicje typów oraz funkcję wstawiającą do listy
napis z zachowaniem zasady poprzedzania. Do funkcji należy przekazać
wskaźnik do listy oraz wstawiany napis, funkcja powinna zwrócić wartość
logiczną wskazującą, czy udało się wstawić napis do listy. Po wstawieniu
elementu wskaźnik do listy powinien wskazywać na nowo wstawiony element.
*/

struct node{
    string s="";
    node* next=NULL;
}

bool wstaw(node* &head, string str){
    if (head==NULL){
        if (str.back()<str.front()){
            head=new node;
            head->next=head;
            head->s=str;
            return true;
        }
        else return false;
    }
    
    node *p=head, *q=head->next;

    do{
        if (p->s.back()<str.front() and str.back()<q.front()){
            node *n = new node;
            n->next=q;
            n->s=str;
            p->next=n;
            head=n;
            return true;
        }
        p=p->next; q=q->next;

    } while (p!=head);

    return false;
}

int main(){return 0;}