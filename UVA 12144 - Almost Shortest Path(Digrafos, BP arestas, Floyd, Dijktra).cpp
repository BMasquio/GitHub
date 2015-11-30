/*
Os shortest paths podem ter arestas em comum entre si.
Os almost shortest paths não podem ter arestas em comum com os shortest paths.

Não pode aplicar o Dijktra n vezes e remover todas as arestas em sequencia
(n = número de menores caminhos).
Contra exemplo:
4 6
0 3
0 1 2
1 3 1
0 2 1
2 3 3
2 1 1
3 2 1
0 0
*/

#include<iostream>
#include<string.h>
using namespace std;
#define NVM 501
#define INF 1000000000

// Declarações para o grafo
int n, m, E[NVM][NVM], Seg[NVM][NVM], Di[NVM][NVM], Dist[NVM], pre[NVM], VCM[NVM][NVM], CM[NVM];
bool Vi[NVM][NVM], Marcado[NVM];
int start, destino;

void Inicializa(int n){
    memset(E, 0, sizeof(E));
    memset(Seg, 0, sizeof(E));
    memset(VCM, 0, sizeof(VCM));
    memset(Vi, false, sizeof(Vi));
    memset(Marcado, false, sizeof(Marcado));
    memset(pre, 0, sizeof(pre));
    for (int i=1; i<=n; i++) Dist[i]=INF;
}


void BP(int u, int v){
	Marcado[v] = true;
//	cout << "BP(" << u <<"," << v << ")" << endl;
	for(int i=1;i<=n;i++)
		if(E[v][i] && !Vi[v][i]/*&& !Marcado[i]*/){
	//		cout << "Aresta " << v << "," << i << endl;
	//		cout << Di[start][v] << "+" << E[v][i] << "+" << Di[i][destino] << " = " << Di[start][destino] << " ?"<<endl;
			if(Di[start][v] + E[v][i] + Di[i][destino] == Di[start][destino]){
				Seg[v][i] = 0;
	//			cout << "Aresta " << v << "," << i << " faz parte de um menor caminho" << endl;
			Vi[v][i] = true;
			
			BP(v,i);
			
			}
		}
	Marcado[v] = false;
}

void Floyd(){
	for(int i=1; i<= n; i++)
		for(int j=1; j<= n; j++){
		    if ((i == j) || (E[i][j])) {
                Di[i][j]=E[i][j];  VCM[i][j]=i;
            }          
		    else Di[i][j] = INF;
        }
	for(int k=1; k<=n; k++)
		for(int i=1 ; i<=n; i++)
			if((Di[i][k] > 0))
				for(int j=1; j<=n; j++)
					if((i != j) && (Di[k][j] > 0) &&
					(!Di[i][j] || (Di[i][j] > (Di[i][k] + Di[k][j])))){
						Di[i][j] = Di[i][k] + Di[k][j];
                        VCM[i][j] = VCM[k][k];                         
                    }
}

void Distjkstra(int v){
	int i, j, w, z;
    Dist[v]=0;
    for(i=1; i<= n; i++){
		for(j=1; j<= n; j++)
		    if (!pre[j]){  w=j;  break; }    
    	for(j=w+1; j<= n; j++)
	        if ((!pre[j]) && (Dist[j] < Dist[w])) w=j; 
	    pre[w]=1;    
        for (z=1; z<=n; z++)
            if ((Seg[w][z]) && (!pre[z]) && (Dist[z] > Dist[w]+Seg[w][z]))
                Dist[z]=Dist[w]+Seg[w][z];
            
    }
}


int main(){
	
	
	int t,u, v, p;
	    int op, uep;
	    while(cin >> n >> m, n||m){
	    	
	    	cin >> op >> uep;
	    	
	    	Inicializa(n);
	    	
	    //	cout << n << " " << m << endl;
	    	
	    	for(int i=1; i<=m; i++){
		    	cin >>u>>v>>p;
		    	E[u+1][v+1]= p;
		    	Seg[u+1][v+1]= p;
	    	}
	    	start = op+1;
	    	destino = uep+1;
	    	
	    	Floyd();
	    	
	    //	for(int i=1; i<=n; i++)
	    //		if(!Marcado[i])
	    			BP(start,start);
	    	
	    	
	    	Distjkstra(start);
	    	
	    	
	    	if((Dist[destino] == INF)) cout << -1 << endl;
	    	else cout << Dist[destino] << endl;
	    
	    }
	return 0;
}
