#include <iostream>

using namespace std;

void hanoi(int n, int z, int na, int pom){
    //hanoi(100,1,2,3)
    // n - ile klocków przenosimy
    // z - z której wieży
    // na - na którą wieżę
    // pom - przy pomocy której
    if (n==1)
        cout<<"Krążek 1 z wieży "<<z<<" na wieżę "<<na<<endl;
    else{
        hanoi(n-1,z,pom, na);
        cout<<"Krążek "<<n<<" z wieży "<<z<<" na wieżę "<<na<<endl;
        hanoi(n-1,pom,na,z);
    }
}

int main(){
    hanoi(3,1,3,2);
    return 0;
}
