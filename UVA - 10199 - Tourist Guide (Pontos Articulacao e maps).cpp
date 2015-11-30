#include <iostream>
#include <map>
#include <string.h>


#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

vector<vii> AdjList;
vi dfs_parent;
vector<string> alfa;

vi dfs_num;     // this variable has to be global, we cannot put it in recursion
int numCC;


vi dfs_low;       // additional information for articulation points/bridges/SCCs
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;


void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
	    ii v = AdjList[u][j];
	    if (dfs_num[v.first] == DFS_WHITE) {                          // a tree edge
	      dfs_parent[v.first] = u;
	      if (u == dfsRoot) rootChildren++;  // special case, count children of root
	
	      articulationPointAndBridge(v.first);
	

	      if (dfs_low[v.first] >= dfs_num[u])              // for articulation point
	 //       articulation_vertex[u] = true;           // store this information first

	        
	      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);       // update dfs_low[u]
	    }
	    else if (v.first != dfs_parent[u])       // a back edge and not direct cycle
	      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);       // update dfs_low[u]
	} 
	
	if(dfs_low[u] >= dfs_num[u]) articulation_vertex[u] = true;
}



map<int, string> intstr;
map<string, int> strint;

int main() {
	
	string str,str1,str2;
	int i,m,temp=0;
	int V, cont;
	
	cin>>V;
	while(V){
		cont=0;
		for(i=0;i<V;i++){
			cin >> str;
			intstr[i] = str;
			strint[str] = i;
		}
		cin >> m;
		AdjList.assign(V, vii());
		alfa.assign(V,"");
		
	  	for (int i = 0; i < m; i++) {
	      cin >> str1 >> str2;
	      AdjList[strint[str1]].push_back(ii(strint[str2], 0));
	      AdjList[strint[str2]].push_back(ii(strint[str1], 0));
	    }
	    
	    dfsNumberCounter = 0; dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0);
		  dfs_parent.assign(V, -1); articulation_vertex.assign(V, 0);
		  for (int i = 0; i < V; i++)
		    if (dfs_num[i] == DFS_WHITE) {
		      dfsRoot = i; rootChildren = 0;
		      articulationPointAndBridge(i);
		      articulation_vertex[dfsRoot] = (rootChildren > 1); }       // special case
		  

		  for (int i = 0; i < V; i++)
		    if (articulation_vertex[i]){
		    	alfa[cont] = intstr[i];
		    	cont++;
		    }
		  cout << "City map #" << ++temp << ": " << cont << " camera(s) found" <<endl;
			
		  	
		  sort(alfa.begin(), alfa.begin()+cont);
		  
		  for (int i = 0; i < alfa.size(); i++)
		      if(alfa[i] != "") cout << alfa[i] << endl;
		  
		  
		  if (cin >> V,V) {cout << endl; continue;} 
	}
	
	
	
	return 0;
}