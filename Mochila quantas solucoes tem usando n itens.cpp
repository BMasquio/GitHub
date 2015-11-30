#include <iostream>
using namespace std;

int soma,S[100],n;
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

void Mochila(int t,int W[],int M){
	
	int i,j,p;
	int K[t+1][M+1];
	
	
	K[0][0] = 1;
	for (j=1;j<=M;j++) K[0][j] = 0;
	for (i=1;i<=t;i++){
		for (j=0;j<=M;j++) K[i][j] = 0;
		for (p=i;p>0;p--)
			for (j=W[i];j<=M;j++)
				if ((K[p-1][j-W[i]] >= 1))
					K[p][j]++;
	}


	//Imprimir
	
	/*
		for(j=1;j<=M;j++){
			cout << K[n/2][j] << " ";
			if(K[n/2][j] > 0)	S[j]++;
		}
		*/
		
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
	int i;
	
	cin >> n;
	
	/*
	for (i=0;i<=9*(n/2);i++){
		V[i+1] = i/2;
	//	cout << V[i+1] << " " << endl;
	}
	V[i+1] = 9;
	
	
	Mochila(10*(n/2),V,9*(n/2));
	
	for(i=1;i<=9*(n/2);i++){
		soma+=S[i]*S[i];
	}
		
	cout << soma ;
	*/
	
	
	V[1]=2;
	V[2]=2;
	V[3]=2;
	V[4]=4;
	V[5]=4;
	
	Mochila(5,V,14);
	
	return 0;
}