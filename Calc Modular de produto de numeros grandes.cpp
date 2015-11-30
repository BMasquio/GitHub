
#include <iostream>
#define MAX 1000000007
//#define MAX 999

/*
O programa faz calculo modular de produtos grandes

A funcao Prod faz (n*k)%MAX
A funcao FatMod faz (n!)%MAX

*/

using namespace std;

long long Prod(long long n, long long k){
     if(k==1) return (n%MAX);
     else{
          long long m=k/2, valor = Prod(n,m); bool resto = (k%2);
     //     cout << "Prod(" << n << "," << k << ") = " << ((valor+valor+resto)%MAX) << endl;
          return ((valor+valor+(resto*n))%MAX);
          }     
}

long long FatMod(int n){
     if (n<2) return 1;
     else return Prod(n,FatMod(n-1));
}

int main(){
    long long i=9999;
    cout << "FatMod(" << i << ") = " << FatMod(i) << endl;
    return 0;
}
