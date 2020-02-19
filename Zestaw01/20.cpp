#include <iostream>
#include "math.h"

using namespace std;

int main(){
    //eps-dokładość przybliżenia
    double a,b,an,bn, eps=0.0000001;
    cin>>a>>b;  
    while (abs(a-b)>eps){
        an=sqrt(a*b);
        bn=0.5*(a+b);
        a=an;
        b=bn;
    }
    cout<<a<<" ";

    return 0;
}