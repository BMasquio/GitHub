#include <iostream>
#include <map>
#include <string.h>
#define INF 1000000000

using namespace std;

int E[100][100];
bool Marca[100], E1[100][100];
int cont;
int n,m,caso;

void Inicializa(){
	memset(E1,false,sizeof(E1));
	memset(Marca,false,sizeof(Marca));
}

void Imprime(){
     for (int i = 1; i <= n; i++){
	    	for (int j = 1; j <= n; j++)
            cout << E[i][j] << " ";
            cout << endl;
            }
}

int auxcon;
void Conexo(int a){
	auxcon++; Marca[a] = true;
	for (int j = 1; j<= n;j++){
		if(E1[a][j] && !Marca[j]){
			Conexo(j);
		}
	}
}

int main() {
	string s1,s2;
	
	
	caso=0;
	
	while(cin >> n >> m, n){
		Inicializa();
		cont=0;
		map <string, int> mapa;
    	map <int, string> mapais;
		
		for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++)
	      E[i][j] = INF;
	      E[i][i] = 0;
	  	}
		
		while(m--){
			cin >> s1 >> s2;
			if(mapa[s1] == 0){
				mapa[s1] = ++cont;
				mapais[cont] = s1;
			}
			if(mapa[s2] == 0){
				mapa[s2] = ++cont;
				mapais[cont] = s2;
			}
			E[mapa[s1]][mapa[s2]] = 1;
			E[mapa[s2]][mapa[s1]] = 1;
			
            E1[mapa[s1]][mapa[s2]] = true;
			E1[mapa[s2]][mapa[s1]] = true;
			
		}
		int maior = 0;
		for (int k = 1; k <= n; k++) // common error: remember that loop order is k->i->j
	    for (int i = 1; i <= n; i++)
	      for (int j = 1; j <= n; j++)
	        E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
		
		for (int i = 1; i <= n; i++)
	    	for (int j = 1; j <= n; j++)
	    		if((E[i][j] > maior)&&(E[i][j] != INF)) maior = E[i][j];
		
	//	Imprime();
		
		auxcon=0;
		Conexo(1);
		
		
		cout << "Network "<<++caso<<": "; 
		if (auxcon == n) cout << maior << endl;
		else cout << "DISCONNECTED" << endl;
		cout << endl;
	}
	
	return 0;
}
