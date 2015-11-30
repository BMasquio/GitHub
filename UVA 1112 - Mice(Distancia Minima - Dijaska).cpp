#include<iostream>
#include <string.h>
#define MAX 2147483485
using namespace std;
const int NVM=150;

// Declarações para o grafo
int n, m, E[NVM][NVM], Di[NVM], pre[NVM];
//Outras declarações
int i, j, u, w, p, z;

void Inicializa(){
    memset(E, -1, sizeof(E));
    memset(pre, 0, sizeof(pre));
    fill(Di, Di+NVM, MAX);
}

int Solucao(int e, int temp){
	int cont;
	Di[e] = 0;
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(!pre[j]){
				w = j;
				break;
			}
		}
		
		for(j = w+1; j <= n; j++){
			if((!pre[j]) && (Di[j] < Di[w])){
				w = j;
			}
		}
		
		pre[w] = 1;
		
		for(z = 1; z <= n; z++){
			if((pre[z] == 0) && (E[w][z] > -1)){
				if(Di[w] + E[w][z] < Di[z]) Di[z] = Di[w] + E[w][z];
			}
		}
	}
	cont = 0;
	for(i = 1; i <= n; i++)//{
		if(Di[i] <= temp) cont++;
		//cout << Di[i] << " ";
		
	
	//}
	//cout << endl;
	return cont;
}

int main(){
	int t, exi, temp;
	cin >> t;

	while(t--){
		cin >> n >> exi >> temp >> m;
	    Inicializa();
	    
	    for(i=1; i<=m; i++){
		    cin >> u >> w >> p;
		    E[w][u] = p;
	    }

	    cout << Solucao(exi, temp) << endl;
	    if(t) cout << endl;
    }
	return 0;
}