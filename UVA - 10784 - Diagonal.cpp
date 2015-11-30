#include <iostream>
#include <math.h>

using namespace std;

long long Absoluto(double n){
     return ((long long)n);
}

double Eqraiz[2];
int qtdraiz;
void Eq2grau(int a, int b, long long c){
    double delta = ((b*b)-(4*a*c));
    if (delta < 0) {qtdraiz=0;}
        else if (delta == 0){ Eqraiz[0] = ((-b)+sqrt(delta))/2*a; qtdraiz=1; }
                 else { Eqraiz[0] = ((-b)+sqrt(delta))/2*a; Eqraiz[1] = ((-b)-sqrt(delta))/2*a; qtdraiz=2;}
}

long long Teto(double n){
     long long temp = Absoluto(n);
     if ((double)temp != n) return(temp+1);
         else return temp;
}

long long Piso(double n){
     return (Absoluto(n));
}


int main(){
    long long d,result;
    int temp=1;
    
    while(cin >> d, d){
         d*=2;
         Eq2grau(1,-3,-d);
         cout << "Case " << temp++ << ": " << (max(Teto(Eqraiz[0]),Teto(Eqraiz[1]))) << endl;
    }
    return 0;
}
