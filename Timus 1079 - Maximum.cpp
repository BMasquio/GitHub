#include <iostream>
using namespace std;

long long A[1000000],M[1000000];

int main() {
	int i,n;
	
	A[0]=0;
	A[1]=1;
	M[0]=0;
	M[1]=1;
	
	for(i=2;i<1000000;i++){
		if(i%2){
			A[i]=A[i/2]+A[(i/2)+1];
		}
		else{
			A[i]=A[i/2];
		}
		
		if(A[i] > M[i-1]) M[i] = A[i];
		else M[i] = M[i-1];
		
		
	//	cout << "A[" << i << "] = " << A[i];
	//	cout << "M[" << i << "] = " << M[i];
	}
	
	while(cin >> n,n){
		cout << M[n] << endl;
	}
	
	return 0;
}