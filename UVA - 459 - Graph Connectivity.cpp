#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

#include <iostream>

using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

vector<vii> AdjList;

int Val(char c){
	return (c-65);
}


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
  int V, total_neighbors, id, weight;
	int n,v1,v2;
	char c1,c2,c3,v3;
	string s1;
	
	
	cin >> n;
	
	if(n==0) return 0;
	
	//Maior vertice
	
	cin>>c3;
	v3 = Val(c3);
	v3++;
	while(n){
		
		
		
		AdjList.assign(v3, vii()); // assign blank vectors of pair<int, int>s to AdjList
		while((cin >> s1)&&(s1.length()>1)){
			c1 = s1[0];
			c2 = s1[1];
			v1 = Val(c1);
			v2 = Val(c2);
			
			
			AdjList[v1].push_back(ii(v2, 0));
			AdjList[v2].push_back(ii(v1, 0));
			
		//	cout << c1 << " " << c2 << endl;
			
			
		}
		
		numCC = 0;
			dfs_num.assign(v3, DFS_WHITE);    // this sets all vertices' state to DFS_WHITE
			for (int i = 0; i < v3; i++)                   // for each vertex i in [0..V-1]
				 if (dfs_num[i] == DFS_WHITE){            // if that vertex is not visited yet
		    		++numCC; dfs(i);
		    		}   // 3 lines here!
			printf("%d\n", numCC);
		
		c3 = s1[0];
		v3 = Val(c3);
		v3++;
		
		n--;
		if(n) cout << endl;
	}

	
	
  return 0;
}
