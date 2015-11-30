#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

vector<vii> AdjList;

void printThis(char* message) {
  printf("==================================\n");
  printf("%s\n", message);
  printf("==================================\n");
}

vi dfs_num;     // this variable has to be global, we cannot put it in recursion
int numCC;

void dfs(int u) {          // DFS for normal usage: as graph traversal algorithm
  printf(" %d", u);                                    // this vertex is visited
  dfs_num[u] = DFS_BLACK;      // important step: we mark this vertex as visited
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
    if (dfs_num[v.first] == DFS_WHITE)         // important check to avoid cycle
      dfs(v.first);      // recursively visits unvisited neighbors v of vertex u
} }

bool funciona;
int bois,vacas;
int numv,comp;

typedef struct oi{
	int um;
	int dois;
}resultado;


int item;

int M[3000];

resultado result[30000];

int cont;
// note: this is not the version on implicit graph
void floodfill(int u, int color) {
  dfs_num[u] = color;
  
  if(color==1) result[comp].um++;
  else result[comp].dois++;
  
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      floodfill(v.first, (color%2)+1);
    else if (dfs_num[v.first] == color) funciona = false; 
} }

bool Valida(int c, int soma){

	if(c == 1){
		int temp = soma + result[1].um;
		if((temp == bois)||(temp == vacas)) return true;
		temp = soma + result[1].dois;
		if((temp == vacas)||(temp == bois)) return true;
		return false;
	}

	if (!Valida(c-1,soma+result[c].um)){
		if (!Valida(c-1,soma+result[c].dois)) return false;
	}
}


void Mochila(){
	int i,j;
	//itens estao em result[]
//	cout << "comp = " << comp << endl;
//	cout << result[1].dois << endl;
//	cout << result[1].um << endl;

	
	for(i=1;i<comp;i++){
			for(j=(comp-1);j>=0;j--){
				if(M[j] == i-1){
					    M[j+result[i].um] = i;
					    M[j+result[i].dois] = i;
				}
			}
	}
	

	
	
//	for(i=0;i<(1+bois+vacas);i++) cout << M[i] << " ";
	
	/*
	for(i=0;i<comp;i++){
		for(j=0;j<(vacas+bois+1);j++)
			if(M[i][j].valor == -1) cout << "x "; else cout << M[i][j].valor << " ";
			cout << endl;}
			*/
}

int main() {
  int V,b,c,m, total_neighbors, id,i,j,id2, weight=0;
  
int t;
cin>>t;
while(t--){
	funciona = true;
  cin>>b>>c;
  cin>>m;
  V=b+c+1;
  bois = b;
  vacas = c;
  
  AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
  for (int i = 0; i < m; i++) {
      scanf("%d %d", &id, &id2);
      AdjList[id].push_back(ii(id2, 0));
      AdjList[id2].push_back(ii(id, 0));
  }

  
  comp=1;
  dfs_num.assign(V, DFS_WHITE);
  for (numv = 1; numv < V; numv++){
  	result[comp].um=0;
  	result[comp].dois=0;
    if (dfs_num[numv] == DFS_WHITE){
      floodfill(numv, 1);
      comp++;
  	}
  }

 // for (int i = 1; i < V; i++)
 //   printf("Vertex %d has color %d\n", i, dfs_num[i]);
  
  bois = b; vacas = c;
 
 

 
 	for(j=0;j<(b+c+1);j++)
 		M[j]=-1;
 //memset(M,it,sizeof(M));
 
 bool valida = false;
 M[0] = 0;
 
 Mochila();
 comp--;
 
// for(i=0;i<usar;i++) if(A[comp-1][i] == bois) valida = true;
 if((M[bois] == comp)||(M[vacas] == comp)) valida = true;
 
 if((funciona)&&(valida)) cout << "yes" << endl;
 else cout << "no" << endl;
}
  return 0;
}
