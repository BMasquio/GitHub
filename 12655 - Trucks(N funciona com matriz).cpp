#include<iostream>
#include<string.h>
using namespace std;
#define NVM 200
#define INF 1000000000

// Declarações para o grafo
int n, m, E[NVM][NVM], Di[NVM][NVM];
int start, destino;

void Inicializa(int n){
    memset(E, 0, sizeof(E));
 //   memset(Seg, 0, sizeof(E));
 //   memset(VCM, 0, sizeof(VCM));
 //   memset(Vi, false, sizeof(Vi));
 //   memset(Marcado, false, sizeof(Marcado));
 //   for (int i=1; i<=n; i++) Dist[i]=INF;
}



void Floyd(){
	for(int i=1; i<= n; i++)
		for(int j=1; j<= n; j++){
		    if ((i == j) || (E[i][j])) {
                Di[i][j]=E[i][j];//  VCM[i][j]=i;
            }          
		    else Di[i][j] = INF;
        }
	for(int k=1; k<=n; k++)
		for(int i=1 ; i<=n; i++)
			if((Di[i][k] != INF))
				for(int j=1; j<=n; j++)
					if((i != j) && (Di[k][j] != INF) &&
					((!Di[i][j]) || Di[i][j] == INF || (Di[i][j] < min(Di[i][k], Di[k][j])))){
						Di[i][j] = min(Di[i][k] , Di[k][j]);
                     //   VCM[i][j] = VCM[k][k];                         
                    }
}


int main(){
	
	
	int u, v, p,s,i;
	    while(cin >> n >> m >> s){
	    	
	    	
	    	
	    	Inicializa(n);
	    	
	    //	cout << n << " " << m << endl;
	    	
	    	for(i=1; i<=m; i++){
		    	cin >>u>>v>>p;
		    	E[u][v]= p;
		    	E[v][u]= p;
		//    	Seg[u][v]= p;
	    	}
	    	
	    	
	    	Floyd();
	    	
	    	for(int i=1; i<=s; i++){
	    		cin >> start >> destino;
	    		cout << Di[start][destino] << endl;
	    	}
	    	
	    	
	   // 	Distjkstra(start);
	    	
	    	
	    //	if((Dist[destino] == INF)) cout << -1 << endl;
	    //	else cout << Dist[destino] << endl;
	    
	    }
	return 0;
}
