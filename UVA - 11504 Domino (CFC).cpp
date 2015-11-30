#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

int t;
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

// note: this is not the version on implicit graph
void floodfill(int u, int color) {
  dfs_num[u] = color;                            // not just a generic DFS_BLACK
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      floodfill(v.first, color);
} }

vi topoSort;             // global vector to store the toposort in reverse order

void dfs2(int u) {    // change function name to differentiate with original dfs
  dfs_num[u] = DFS_BLACK;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      dfs2(v.first);
  }
  topoSort.push_back(u); }                   // that is, this is the only change

#define DFS_GRAY 2              // one more color for graph edges property check
vi dfs_parent;      // to differentiate real back edge versus bidirectional edge

void graphCheck(int u) {               // DFS for checking graph edge properties
  dfs_num[u] = DFS_GRAY;   // color this as DFS_GRAY (temp) instead of DFS_BLACK
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE) {     // Tree Edge, DFS_GRAY to DFS_WHITE
      dfs_parent[v.first] = u;                  // parent of this children is me
      graphCheck(v.first);
    }
    else if (dfs_num[v.first] == DFS_GRAY) {             // DFS_GRAY to DFS_GRAY
      if (v.first == dfs_parent[u])          // to differentiate these two cases
        printf(" Bidirectional (%d, %d) - (%d, %d)\n", u, v.first, v.first, u);
      else  // the most frequent application: check if the given graph is cyclic
        printf(" Back Edge (%d, %d) (Cycle)\n", u, v.first);
    }
    else if (dfs_num[v.first] == DFS_BLACK)             // DFS_GRAY to DFS_BLACK
      printf(" Forward/Cross Edge (%d, %d)\n", u, v.first);
  }
  dfs_num[u] = DFS_BLACK;     // after recursion, color this as DFS_BLACK (DONE)
}

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
        articulation_vertex[u] = true;           // store this information first
      if (dfs_low[v.first] > dfs_num[u])                           // for bridge
        printf(" Edge (%d, %d) is a bridge\n", u, v.first);
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);       // update dfs_low[u]
    }
    else if (v.first != dfs_parent[u])       // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);       // update dfs_low[u]
} }

vi S, visited;                                    // additional global variables
int numSCC;
int n,m;

int qtd=0;
int R[1110000];

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      tarjanSCC(v.first);
    if (visited[v.first])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }
//	memset(R,0,n+10);
  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC

    while (1) {
      int v = S.back(); S.pop_back(); visited[v] = 0;
      //printf(" %d", v);
 
      R[v] = u;
      
      if (u == v) break;
    }
} }

void Domino(){
	int u,i;
	int V1[100100];
	
	fill(V1,V1+n+10,0);
	
	for(i=1;i<=n;i++){
	    for (int j = 0; j < (int)AdjList[i].size(); j++) {
	    	ii v = AdjList[i][j];
	    	//u = dfs_parent[v.first];
	    	
	    	if(R[v.first] != R[i]) V1[R[v.first]]++;
	    }
	}
	
//	for(i=1;i<=n;i++){
//		cout << R[i] << " " ;
//	}
//	cout << endl;
	
	for(i=1;i<=n;i++){
		if((V1[i] == 0) &&(R[i]==i)) qtd++;
	}
}



int main() {
  int V, total_neighbors, id, weight;

  int temp1,temp2;

  cin >> t;
  

  
  while(t){
	  cin>>n>>m;
	  V=n;
	  qtd=0;
	  
	  AdjList.assign(V+1078, vii()); // assign blank vectors of pair<int, int>s to AdjList
	  for (int i = 0; i < m; i++) {
	      cin >> temp1 >> temp2;
	      AdjList[temp1].push_back(ii(temp2, 0));
	  }
	
	  
	  dfs_num.assign(V+1053, DFS_WHITE); dfs_low.assign(V+1340, 4564560); visited.assign(V+1530, 0456);
	  S.assign(V+1580, 6650);
	  dfsNumberCounter = numSCC = 0;
	  
	  for (int i = 1; i <= V; i++)
	    if (dfs_num[i] == DFS_WHITE)
	      tarjanSCC(i);
	  
	  Domino();
	  /*
	  dfs_low.clear();
	  dfs_num.clear();
	  visited.clear();
	  AdjList.clear();
	  */
	  cout << qtd << endl;
	  t--;
  }
  return 0;
}
