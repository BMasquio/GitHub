#include <iostream>
#include <string.h>
using namespace std;

#define DEBUG(A) cout << "[DEBUG]" << #A << "=" << A << endl
#define LIMPA(A) memset(A,0,sizeof(A))

int n,m,temp;
unsigned long long B1[10], B2[10];

int main() {
	int i;
//	F[0] = 1;
//	F[1] = 1;
//	for(i=2; i<10; i++){
//		F[i] = F[i-1]*i;
	//	cout << F[i] << endl;
//	}
	
	while(cin >> n >> m, n && m){
		int i;
		LIMPA(B1);
		LIMPA(B2);
		unsigned long long b1=1,b2=1;
		
		while(n--){
			cin >> temp;
			for(i=2; i<=temp; i++) B1[i]++;
		}
		while(m--){
			cin >> temp;
			for(i=2; i<=temp; i++) B2[i]++;
		}
		
		
		
		while(B1[4]){
			B1[4]--;
			B1[2]+=2;
		}
		while(B1[6]){
			B1[6]--;
			B1[2]++;
			B1[3]++;
		}
		while(B1[8]){
			B1[8]--;
			B1[2]+=3;
		}
		while(B1[9]){
			B1[9]--;
			B1[3]+=2;
		}
		
		while(B2[4]){
			B2[4]--;
			B2[2]+=2;
		}
		while(B2[6]){
			B2[6]--;
			B2[2]++;
			B2[3]++;
		}
		while(B2[8]){
			B2[8]--;
			B2[2]+=3;
		}
		while(B2[9]){
			B2[9]--;
			B2[3]+=2;
		}
		
		
		bool foi = true;
		for(i=2;i<10;i++){
			if(B1[i] != B2[i]){foi = false; break;} 
		}
		
	//	DEBUG(b1);
	//	DEBUG(b2);
		
		if(foi) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}