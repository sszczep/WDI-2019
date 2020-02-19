#include <iostream>
using namespace std;

/* 28. Lista reprezentuje wielomian o współczynnikach całkowitych. Elementy w
liście ułożone są według rosnących potęg. Proszę napisać funkcję
obliczającą różnicę dwóch dowolnych wielomianów. Wielomiany reprezentowane
są przez wyżej opisane listy. Procedura powinna zwracać wskaźnik do nowo
utworzonej listy reprezentującej wielomian wynikowy. Listy wejściowe
powinny pozostać niezmienione */

struct node
{
    int val;
    node* next;
};

node* odejmijWielomiany (node * P, node * Q){
    node *wynik = new node;
    node *w=wynik;
    
    while (true){
        
        w->val=P->val-Q->val;
        P=P->next;
        Q=Q->next;    
        
        if (P==NULL or Q==NULL) break;
        
        w->next=new node;
        w=w->next;
    }

    if (P==NULL and Q==NULL){
        w->next=NULL;
        return wynik;
    }
    
    if (Q!=NULL) P=Q;
    //if (P!=NULL) P=P;
    //P tutaj będzie wskazywać na kolejne współczynniki 
    //wielomianu o wyższym stopniu

    do{
        w->next=new node;
        w=w->next;

        w->val=P->val;
        P=P->next;
    while (P!=NULL);

    w->next=NULL;
     
    return wynik;

}

int main() {return 0;}

