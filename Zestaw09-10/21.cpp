#include <iostream>

struct node{
    node* next;
    int val;
}

//algorytm Floyda
int precycleLength(node* head){
    node *p, *q;
    p=q=head;
    while (true){
            p=p->next;
            q=q->next->next;
            if (p==q) break;
    }
    int cnt=0;
    p=head;
    while (p!=q){
        p=p->next;
        q=q->next;
        cnt++;       
    }
    return cnt;
}

//To działa dlatego, że p i q spotykają się na pozycji -d mod l w cyklu
//gdzie l - długość cyklu, d - długość tego co przed cyklem
//wynika to z tej analizy:
/*
 - Jeżeli lista nie ma cyklu, to w pewnym momencie q natrafi na NULL i funkcja zwróci false

 - Jeżeli funkcja ma cykl długości d, to zajdzie następująca sytuacja:
    p: na pozycji 0 w cyklu
    q: na pozycji a w cyklu: a należy do {0...d-1}

Szukamy liczby ruchów k takiej, że po k ruchach od tego momentu
    
    pozycja p = pozycja q

Co zachodzi wtedy, gdy:
        0 + k ≡ a + 2k (mod d)

Przekształcamy równoważnie kongruencję:
        k - a ≡ 2k     (mod d)
            k ≡ -a     (mod d)

    czyli   k = -a + n*d ,     n jest pewną liczbą całkowitą

Jeżeli a=0 to k=0;
Jeżeli a!=0 to k=d-a
    
Czyli w przypadku gdy lista ma cykl, wskaźniki p i q na pewno się spotkają i funkcja zwróci true
Co więcej, wiemy że spotkają się na pozycji d-a.
*/