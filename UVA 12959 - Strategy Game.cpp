#include <iostream>
using namespace std;

int main() {
	int j,r;
	
	
	while(cin >> j >> r){
		
		int i,maxv=0,maxp=0,val;
		int P[600];
		while(r--){
			for(i=0;i<j;i++){
				cin >> val;
				P[i]+=val;
				if(P[i] >= maxv){
					maxp = i;
					maxv = P[i];
				}
			}
		}
		
		cout << maxp+1 << endl;
	}
	
	return 0;
}