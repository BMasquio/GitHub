#include <iostream>
#include <string.h>
using namespace std;

int E[200][200],pre[200],UOPI[200];
int i,maior,qtd,V;

void BP(int x){
	int j;
	pre[x] = 1;
	for(j = 0; j< V; j++){
		if((pre[j]==0)&&(E[x][j])){
			BP(j);
			UOPI[i]++;
		}
	}
}

void Inicializa(){
	memset(E,0,sizeof(E));
	memset(pre,0,sizeof(pre));
	memset(UOPI,0,sizeof(UOPI));
}

int main() {

	while(cin >> V, V){
		maior = 0;
		qtd =0;
		Inicializa();
		int m,wa;
		for(i=0;i<V;i++){
			cin >> m;
			for(int j = 0;j<m;j++){
				cin >> wa;
				E[i][wa-1] = 1;
			}
		}
		
		for(i = 0; i < V;i++){
			memset(pre,0,sizeof(pre));
			if(pre[i] == 0){
				BP(i);
			}
		}
		
		int maior =0;
		int mv;
		
		for(i=0;i<V;i++){
			if(UOPI[i] > maior){
				maior = UOPI[i];
				mv = i;
			}
		}
		
		cout << (mv+1) << endl;
	}
	return 0;
}