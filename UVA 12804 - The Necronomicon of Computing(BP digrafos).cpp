#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool Adj[1010][1010];
int T[1010];
int M[1010];
bool chegou, ciclo;
	int n,m,pre,pos;


void BP(int a){
	int i, j;
	bool chega = true;
	
//	cout << a << endl;
	
	if(a == m){chegou = true; return;}
	
	if(M[a] == 0) M[a] = ++pre;
	
	//cout << "pre = " << pre << endl;
	
//	if(a == m){chegou = true; return;}
	
	for(i=0; i<=m; i++){
		if(Adj[a][i]){
	//		
	//		cout <<  a << " e " << i << endl;
		//	cout << "M[a] = " << M[a] << " M[i] = " << M[i] << endl;
			
		//	cout << "T[i] = " << T[i] << endl;
			
			if(M[i] == 0){
				BP(i);
			}
			else if (T[i] == 0){
				ciclo = true;
		//		cout << "Ciclo em " << a << " e " << i << endl;
			}
		}
	}
	
//	C[i] = chega;
	T[a] = ++pos;
	return;
}


int main() {
	string c;
	int temp, cont;
	
	cin >> n;
	
	while(n--){
		cont=0;
		cin >> m;
		
		int tt = m;
		
		pre=0;
		pos =0 ;
		memset(Adj,false,sizeof(Adj));
			memset(M,0,sizeof(M));
			memset(T,0,sizeof(T));
			
			chegou = false;
			ciclo = false;
		
		while(tt--){
			cin >> c;
			
			
			
			if(c=="A") {Adj[cont][cont+1] = true;}
			else if(c=="J") {cin >> temp; Adj[cont][temp-1] = true;}
			else {Adj[cont][cont+1] = true; cin >> temp; Adj[cont][temp-1] = true;}
			cont++;
		}
			
			int i,j;
			/*
			for(i=0;i<=m;i++){
				for(j=0;j<=m;j++){
					cout << " " << (int)Adj[i][j];
				}
				cout << endl;
			}
			*/
			
	//		Adj[m-1][m] = true;
			
			BP(0);
			
			if(chegou){
				if(ciclo){
					cout << "SOMETIMES" << endl;
				}
				else{
					cout << "ALWAYS" << endl;
				}
			}
			else{
				cout << "NEVER" << endl;
			}
	}
	
	return 0;
}