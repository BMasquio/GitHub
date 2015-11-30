#include <iostream>
using namespace std;
#define MOD 1000000007

/*

Ideia: Dividir o problema em:
- Cada equipe tem um capitao (n)
- O resto da equipe pode ter qualquer numero de pessoas (2^(n-1))
	Todos os possiveis subconjuntos do resto do time

Otimizacao em Pot2

*/

long long Pot2(long long p)
    {
    	if(p == 1) return 2;
        long long m=p/2, valor = Pot2(m); bool resto = (p%2);
        if (resto) return ((valor*valor*2)%MOD);
        else return ((valor*valor)%MOD);
    }
int main ()

{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++) {
        int n;
        cin>>n;
        cout<<"Case #"<<i<<": ";
        if(n==1)
        cout<<"1"<<endl;
        else
        cout << (((Pot2(n-1)%MOD) * (n%MOD)) % MOD) << endl;
    }
return 0;
}