#include <iostream>
#include <string.h>
using namespace std;

#define DEBUG(A) cout << "[DEBUG]" << #A << "=" << A << endl
#define LIMPA(A) memset(A,0,sizeof(A))

int Seq[51000];
int Soma[51000];

int main() {
	int i,j,k,n,m, cont=0;
	
	cin >> n;
	
	while(n--){
		long long unsigned resp=0;
		cin>>m;
		
//		LIMPA(Seq);
//		LIMPA(Soma);
		
		Soma[0] = 0;
		for(i=1; i<=m ;i++){
			cin >> Seq[i];
			Soma[i] = Soma[i-1] + Seq[i];
		}		
		
		int minimo;
		for(i=1;i<=m;i++){
			minimo = Seq[i];
			for(j=(i+1); j<=m; j++){
				minimo = min(minimo, Seq[j]);
				resp += Soma[j] - Soma[i-1] - (minimo*(j-i+1));
			}
		}
		
		cout << "Case " << ++cont << ": " << resp << endl;
	}
	
	return 0;
}