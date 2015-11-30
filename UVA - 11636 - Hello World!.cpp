#include <iostream>
using namespace std;

long long T[100];

int main() {
	T[0]=1;
	int i,j,n;
	
	for(i=1;i<100;i++) T[i]=T[i-1]*2;
	j=0;
	while(cin>>n,n>0){
		
		j++;
		i=0;
		
		while(n>T[i]) i++;
		
		cout << "Case " << j << ": " << i << endl;
		
	}
	
	return 0;
}