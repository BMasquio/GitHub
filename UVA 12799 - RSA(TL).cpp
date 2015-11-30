#include <iostream>
#include <math.h>
using namespace std;



long long unsigned n1,e,c,d,m,fator[2],i,j,fi;







int C[10000001], P[1000001], rq, nf, np, nd;
long long int n, q, F[50], D[10000];
bool teste;

void GeraCrivo (int n)
{    int i, rq, t, d;
     for (i=1; i<=n; i++)   C[i] = i;
     for (i=2; i<=n; i+=2)  C[i] = 2;
     rq = sqrt(n);
     for (i=3; i<=rq; i+=2)
     {   if (C[i] == i)
         {   t = i*i;  d = i+i;
             while(t<=n)
             {   if (C[t] == t) C[t] = i;
                 t = t+d;
             }
         }
     }
}
void GeraPrimos (int rq)
{    np=0;
     for (int i=2; i<=rq; i++)
         if (C[i]==i)  P[++np]= i;
}

bool TestaPrimo (long long int q)
{    bool primo = true;
     for (int i=1; i<=np; i++)
     {   if ((q % P[i]) == 0)
         {   if (q != P[i]) primo = false;
             break;
         }    
     }
     return (primo);
}

void Fatora (long long int q)
{    nf = 0;
     for (int i=1; i<=np; i++)
     {   while((q % P[i]) == 0)
         {   F[++nf] = P[i];  q = q/P[i];
         }
         if (q == 1) break;
     }
     if (q != 1) F[++nf] = q;
}

void Divisores(long long int q)
{    int nda;long long int k;
     F[0] = 1;  nd = 1;  D[1] = 1;  nda = 1;
     for (int i=1; i<=nf; i++)
     {   if (F[i] == F[i-1]) k = k*F[i];
         else
         {    nda = nd;  k = F[i];
         }
         for (int j=1; j<=nda; j++)
             D[++nd] = k*D[j];
     }
}

















long long unsigned PotMod(int a, int b, int n){
    long long unsigned m, c, d, rb[101];  int i, j;
    m= b;   i= 101;
    while (m > 0){
        rb[--i]= m % 2;   m= m /2;
    }
    c= 0; d= 1;
    for(j=i; j<= 100; j++){
        d= (d*d) % n;    c= 2*c;
        if (rb[j] == 1){
            d= (d*a) % n;   c++;
        }
        //cout << rb[j] << " " << c << " " << d <<endl;
    }
    return (long long unsigned) d;
}



long long unsigned inv(long long unsigned a){
  long long unsigned x;

  for(x=1;x<=n1;x++){
    if((a*x)%fi==1)
      return x;
  }

}

int main() {
	
	rq = 10000000;  n = rq;  n = n*n;
	GeraCrivo(rq);
    GeraPrimos(rq);
	
	
	while(cin >> n1 >> e >> c){
		j=0;
		

		Fatora(n1);
	//	int raiz = (int)sqrt((double)n);
	//	raiz++;
		
	//	cout << raiz << endl;
		/*
		for(i=2;i<=n1;i++){
			if(n%i == 0) {fator[j] = i; j++;}
		}
		*/
		

		
		fi = (F[1]-1)*(F[2]-1);
		
		d = inv(e);
		
		//c^d % n
		
		cout << PotMod(c,d,n1) << endl;
		
	//	cout << fator[0] << " " << fator[1] << endl;
	}
	
	return 0;
}