#include <iostream>
using namespace std;

/*Napisać program wypisujący wszystkie możliwe podziały liczby naturalnej na sumę
składników. Na przykład dla liczby 4 są to: 1+3, 1+1+2, 1+1+1+1, 2+2. */

void roz(int n, int last, string s){ //roz(4,1,"")
    if (n==0)
        cout<<s<<endl;
    else{
        for (int i=last; i<=n;++i){
            roz(n-i,i,s+" "+to_string(i));
        }
    }
}
//do testowania
int main(){
    roz(8,1,"");
    return 0;
}