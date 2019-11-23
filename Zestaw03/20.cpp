#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
#define MAX 10

using namespace std;

bool pierwsza (int n){
    if (n==0 or n==1) return false;
    else if (n==2) return true;
    else if (n%2==0) return false;
    for (int i=3; i*i<=n; i+=2){
        if (n%i==0) return false;
    }
    return true;
}

//zwaraca true, jeżeli suma jest pierwsza i wypisuje ją
bool generuj_sume(int t1[MAX],int t2[MAX],int dodaj[MAX]){
    string s=""; int suma=0;
    for (int i=0; i<MAX; i++){
        if (dodaj[i]==1 or dodaj[i]==3){
            s+=(to_string(t1[i])+"+");
            suma+=t1[i];
        }
        if (dodaj[i]==2 or dodaj[i]==3){
            s+=(to_string(t2[i])+"+");
            suma+=t2[i];
        }
    }
    s.erase(s.size()-1);
    if (pierwsza(suma)){
        cout<<s<<"="<<suma<<endl;
        return true;
    }
    else return false;

}

// generuje następny w porządku leksykograficznym
// ciąg składający się z {1, 2, 3} 
void nastepny(int t[MAX]){
    int pos=MAX-1;
    if(t[pos]<3){
        t[pos]++; return;
    }
    else{
        while(t[pos-1]==3) pos--;
        t[pos-1]++;
        for (;pos<MAX;pos++){
            t[pos]=1;
        }
    }
}

//sprawdza czy ciąg składa się z samych trójek
bool ostatni_ciag(int t[MAX]){
    for (int i=0; i<MAX; ++i){
        if (t[i]!=3) return false;
    }
    return true;
}



int f(int t1[MAX], int t2[MAX]){
/* Funkcja f używa dodatkowej tablicy t[MAX], aby określić czy wybiera
element o danym indeksie z t1, t2 czy z obu tablic.
    jeżeli t[i]==
    1, to do sumy dodajemy t1[i]
    2, to do sumy dodajemy t2[i]
    3, to do sumy dodajemy t1[i] oraz t2[i]*/
   int sum_cnt=0; int t[MAX];

   for (int i=0; i<MAX; i++)
        t[i]=1;
    //zaczynamy od tablicy składającej się z samych jedynek,
    //więc każdy element bierzemy z tablicy t1

    while(true){
        if (generuj_sume(t1,t2,t)) sum_cnt++;
        if (ostatni_ciag(t)) break;
        nastepny(t);
    }
    return sum_cnt;
}

int main(){
    int t1[MAX], t2[MAX],a;
    srand(time(NULL));
    for (int i=0; i<MAX;++i){
        t1[i]=1+rand()%100; cout<<t1[i]<<"\t";
        t2[i]=1+rand()%100; cout<<t2[i]<<endl;
    }
    a=f(t1,t2);
    cout<<"Znaleziono i wypisano "<<a<<" sum.";

    return 0;
}
