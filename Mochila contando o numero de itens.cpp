#include <iostream>
using namespace std;


/*Mochila
K[0,0] ← 0; Para j de 1 a M: K[0,j] ← -1; Fp;
Para i de 1 a t: 
Para j de 0 a M: K[i,j] ← -1; Fp;
Para p de i descendo a 1:
Para j de W[i] a M:
Se (K[p, j] = -1) e (K[p-1,j-W[i]] ≥ 0) Então
K[p, j] ← i;
Fp;
Fp;
Fp;

*/

// Exemplo: W = {7, 3, 5, 9, 15} M = 20
// t = numero de elementos em W
// M = numero maximo da soma que se quer
// M tem que ser no maximo a soma de todos os valores
// W = vetor com os elementos
// prim = primeiro elemento do vetor W

void Mochila(int t,int W[],int M){
	
	int i,j,p;
	int K[t+1][M+1];
	int prim=2;
	
	
	K[0][0] = 0;
	for (j=1;j<=M;j++) K[0][j] = -1;
	for (i=1;i<=t;i++){
		for (j=0;j<=M;j++) K[i][j] = -1;
		for (p=i;p>0;p--)
			for (j=W[i];j<=M;j++)
				if ((K[p][j] == -1)&&(K[p-1][j-W[i]] >= 0))
					K[p][j]=i;
	}
	
	
	//Imprimir
	for(i=1;i<=t;i++){
		
		
		for(j=1;j<=M;j++){
			
			if(K[i][j] > 0)	cout << K[i][j] <<" ";
			else cout << "x ";
		}
		cout << endl;
	}
	
	
}


int main() {
	int V[100];
	int i,n;
	
	cin >> n;
	
	
	
	V[1] = 1;
	V[2] = 2;
	V[3] = 4;
	
	Mochila(3,V,7);
	return 0;
}