#include <iostream>
#include <stack>
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

vi dfs_num;     // this variable has to be global, we cannot put it in recursion
int numCC;

void dfs(int u) {          // DFS for normal usage: as graph traversal algorithm
  dfs_num[u] = DFS_BLACK;      // important step: we mark this vertex as visited
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
    if (dfs_num[v.first] == DFS_WHITE)         // important check to avoid cycle
      dfs(v.first);      // recursively visits unvisited neighbors v of vertex u
} }

int main() {
  int V, id;
	bool par;
	int n,r,i, temp;
	
  while(cin >> n >> r){
	  V=n;
	  
	  par=true;
	  
	  AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
	    for (int j = 0; j < r; j++) {
	      scanf("%d %d", &id,&temp);
	      AdjList[id].push_back(ii(temp, 0));
	      AdjList[temp].push_back(ii(id, 0));
	    }
	
	  numCC = 0;
	  dfs_num.assign(V, DFS_WHITE);    // this sets all vertices' state to DFS_WHITE
	  for (int i = 0; i < V; i++){
	    if (AdjList[i].size() % 2) {par = false; break;}
	    if (dfs_num[i] == DFS_WHITE){            // if that vertex is not visited yet
	      ++numCC; dfs(i);
	    }
	  }
	  
	  if ((numCC == 1)&&(par)) cout << "Possible" << endl;
	  else cout << "Not Possible" << endl;
	  
	}
  return 0;
}
