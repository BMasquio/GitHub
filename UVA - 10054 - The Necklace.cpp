/*Neste programa você vai trabalhar com o algoritmo do Circuito Euleriano,
   com representação em listas de adjacências.  
1. Observe que, com a implementação feita, o algoritmo será O(nm).
2. Melhore a complexidade do algoritmo modificando o procedimento Proxviz.
3. Modifique o algoritmo para que ele possa processar hipergrafos(múltiplas arestas
   entre dois vértices e autoloops.*/
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

vector<vii> AdjList;

const int NVM=1001;

vi dfs_num;     // this variable has to be global, we cannot put it in recursion
int numCC;
/*
void dfs(int u) {          // DFS for normal usage: as graph traversal algorithm
  dfs_num[u] = DFS_BLACK;      // important step: we mark this vertex as visited
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
    if (dfs_num[v.first] == DFS_WHITE)         // important check to avoid cycle
      dfs(v.first);      // recursively visits unvisited neighbors v of vertex u
} }
*/

// Declarações para o grafo
int n, m, E[NVM][NVM],  D[NVM], PROX[NVM];
//Outras declarações
int i,j,u,w,ult,topo, Pil[NVM], T[NVM];

void Inicializa(){
    memset(E, 0, sizeof(E));
    memset(D, 0, sizeof(D));
    memset(T, 0, sizeof(T));
}
void PUSH(int v){
	Pil[++topo] = v;
}

int POP(){
	return Pil[topo--];
}

int Proxviz(int v){
    w=-1;
    for(int j=T[v]; j>=1; j--) if (E[v][j] > 0){
        w = j; T[v] = j; break;
    }
    return w;
}

void Remove(int u,int w){
    E[u][w]--; E[w][u]--;
    D[u]--;  D[w]--;
}

int main(){
		int temp=1,cont,casos;
		
		
		bool conexo,par;
		
		cin >> casos;
		
		
		while(temp <= casos){	
	        cin >> m;
	        n=50;
	        cont =0;
	        stringstream ss;
	        
	        
	        conexo=true;
			par=true;
			
		    Inicializa();
		    
		    for (i=1;i<=n;i++) T[i] = n;
		  //  cout<<"Arestas:"<<endl;	    
		    for(i=1; i<=m; i++){
			    cin >> u >> w;
			    E[u][w]++; E[w][u]++;
			    D[u]++;  D[w]++;
			    
			 //   AdjList[u].push_back(ii(w, 0));
			 //   AdjList[w].push_back(ii(u, 0));
		    }
		    
		    //Verifica se o grau e par
		    for(i=1; i<=n; i++){
		    	if(D[i]%2) {par=false; break;}
		    }
		    
		    //Algoritmo CircuitoEuleriano
	        
	        /*
	        numCC = 0;
			dfs_num.assign(51, DFS_WHITE);    // this sets all vertices' state to DFS_WHITE
			for (int i = 1; i < 51; i++)                   // for each vertex i in [0..V-1]
				 if (dfs_num[i] == DFS_WHITE){            // if that vertex is not visited yet
		    		++numCC; dfs(i);
		    		}   // 3 lines here!
			printf("conected components - %d\n", numCC);
	        */
	        
	        int contador=1;
	        cout<<"Case #"<<temp<<endl;
			    topo = 0;
			    for (i=1;i<51;i++) if(D[i]) {PUSH(i);break;}
			    while(topo){
				    u = Pil[topo];
				    w = Proxviz(u); 
				    
				 //   if(w==-1) {break;}
				    
				    Remove(u,w);
				    PUSH(w);
				    while((topo) && (!(D[Pil[topo]]))){
					    w = POP();
					    if(cont==0) {cont++;}
					    else if(cont==1) {ss << ult << " " << w << endl;}
					    ult = w;
				    }
			    }
			
			for(i=1;i<=n;i++){
	        	if(D[i]) {conexo=false;	break;}
	        }
			
			if((par)&(conexo)){
				cout << ss.str();
			}	        
	        else cout << "some beads may be lost" << endl;
		    
		    
		    
		    
		    
		    
		    
		    cout << endl;
		    temp++;
		}
	return 0;
}


