#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MOD 10000

int V[MOD];
int Bot[10];

struct coisa{
  int niv;
  int valor;
};

int main() {
	int L,U,R,cont=1;
	queue<coisa> fila;
	int i,j,temp;
	coisa c1,c2;
	
	
	while(cin >> L >> U >> R,L||U||R){
		for(i=0;i<10000;i++) V[i]=0;
		
		for(i=0;i<R;i++)
			cin >> Bot[i];
		
		
		
		//O nivel ta com um a mais
		V[L] = 1;
		c1.niv = 1;
		c1.valor = L;
		fila.push(c1);
		
		while(!fila.empty()){
			c1 = fila.front();
			fila.pop();
			for(i=0;i<R;i++){
				temp = (c1.valor+Bot[i])%MOD;
				if (V[temp]==0){
					c2 = c1;
					c2.valor = temp;
					c2.niv++;
					fila.push(c2);
					
				//	cout << "temp = " << temp << endl;
					
					V[temp] = c2.niv;
				}
			}
		}
		
		cout << "Case " << cont++ << ": ";
		if(V[U]) cout << (V[U]-1) << endl;
		else cout << "Permanently Locked" << endl;
	}
	return 0;
}