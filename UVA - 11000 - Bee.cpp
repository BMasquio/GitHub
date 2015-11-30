#include <iostream>
using namespace std;


/*

int M(int n){
	if(n==0) return 0;
	else if (n==1) return 1;
	else return (M(n-1)+M(n-2)+1);
}
*/

long long M[200];

int main() {
	int i=2, n, temp;
	
	M[0]=0;
	M[1]=1;
	
	while(i<300){
		M[i] = M[i-1] + M[i-2] + 1;
		i++;
	}
	

	
	while(cin >> n, (n>-1)){
		if(n==0) cout << "0 1" << endl;
		else cout << M[n] << " " << (M[n-1]+M[n]+1) << endl;
	}
	
	return 0;
}