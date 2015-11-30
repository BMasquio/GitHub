#include <iostream>

using namespace std;

long long V[1000001];

int main(){
	int n,i,j;
	long long soma;
	
	cin >> n;
	
	V[1]=2;
	
	for (i=2;i<1000001;i++){
		V[i]=V[i-1]%1000007+(2+((i-1)*3))%1000007;
		V[i]=V[i]%1000007;
	}
	
	while(n){
		cin >> j;
		
		cout << V[j] << endl;
		
		n--;
	}
}