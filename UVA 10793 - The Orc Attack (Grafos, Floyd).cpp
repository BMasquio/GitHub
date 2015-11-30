#include<iostream>
#include<string.h>
#include <iomanip>

using namespace std;
#define NVM 2001
#define INF 1000000000

// Declarações para o grafo
int n, m, E[NVM][NVM], Di[NVM][NVM], VCM[NVM][NVM], CM[NVM];

void Inicializa(int n){
    memset(E, -1, sizeof(E));
    memset(VCM, 0, sizeof(VCM));    
}

void Floyd(){
	for(int i=1; i<= n; i++)
		for(int j=1; j<= n; j++){
		    if (i == j) {Di[i][j] = 0; VCM[i][j]=i;}
		    else if (E[i][j] > -1){
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


int main(){
	bool conexo;
    int t,u, v, p;
    
    
 //   cout << (int)INF;
 //   return 0;
    
//	while (true){
	   // cout<<"Digrafo com n m = ";  cin >>n>>m;
//	    if (!n) break;
	   // Inicializa(n);
	  //  cout<<"Arestas e pesos:"<<endl;
	    
	    cin >> t;
	    int cont = 0;
	    while(t--){
	    	
	    	conexo = true;
	    	cin >> n >> m;
	    	Inicializa(n);
	    	
	    //	cout << n << " " << m << endl;
	    	
	    	for(int i=1; i<=m; i++){
		    	cin >>u>>v>>p;
		    	if(E[v][u] > -1){
		    	
		    		E[v][u]= min(p,E[u][v]);
		    		E[u][v]= min(p,E[u][v]);
		    	}else{
		    		E[v][u]= p;
		    		E[u][v]= p;
		    	}
	    	}
	    	Floyd();
	    
	    
	    /*
	    	for(int j=1 ; j<=n; j++)
   		for(int k=1; k<=n; k++)
			if((E[j][k]) && (Di[k] > (Di[j]+E[j][k])))
                cout<<"Ciclo negativo detectado no vertice "<<k<<endl; 
	    */
	    	int menor=INF;
	    	int distmaior=INF;
	    	int temp;
	    	bool foi=true;
	    	for(int i=1; i<=n; i++){
	    		temp = Di[1][i];
	    		conexo = true;
	    		foi = true;
	    		
	    		if (temp == INF) conexo = false;
	    		
	    		
	    		
	    		for (int j=2; j<=5; j++){
	    			if (Di[j][i] != temp) {foi = false; break;}
	    			if (Di[j][i] == INF) {conexo = false; break;}
	    		}
	    		
	    		
	    		
	    		if(foi && conexo){
	    			
	    	//		cout << "Vértice " << i << " equidistante" << endl;
	    			
	    			int tempos = Di[1][i];
	    			
	    			for(int k=1; k<=n; k++){
	    					if((Di[i][k] > tempos)) tempos = Di[i][k];
	    					if(Di[i][k] == INF) conexo = false;
	    			}
	    			
	    			if(conexo) if (tempos < distmaior) distmaior = tempos;
	    		}
	    	
	    	}
	    	
	    	
	    	/*
            cout << "Matriz: " <<endl;
            for(int i=1; i<=n;i++){
                    for(int j=1; j<=n; j++){
                            cout.width(3); cout << Di[i][j];}
                    cout << endl;	    
            }
	    	*/
	    	
	    	cout << "Map " << ++cont <<": ";
	    	if(distmaior == INF) cout << -1 << endl;
	    	else cout << distmaior << endl;
	    	
	    }
	    //cout<<"Caminhos minimos: "<<endl;
//	}
	return 0;
}


