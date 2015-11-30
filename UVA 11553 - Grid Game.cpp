#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int M[10][10];

int main() {
	int myints[] = {0,1,2,3,4,5,6,7};
	int n,t,i,j,soma;

	
	cin >> t;
	
	while(t--){
		soma = 9999999;
		
		cin >> n;
	
		sort (myints,myints+8);
			
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				cin >> M[j][i];
			}
		
	//	for(i=0;i<n;i++) cout << " " << myints[i];
		
		do {
    		int sp=0;
    		for(i=0;i<n;i++) sp += M[i][myints[i]];
    		if (sp < soma) soma = sp;
  		} while ( next_permutation(myints,myints+n) );
		
	
		cout << soma << endl;
	}
	
	return 0;
}