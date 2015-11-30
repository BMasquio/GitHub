#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	
	int t0,t1,t2,t3;
	
	while (cin >> t0 >> t1 >> t2 >> t3, t0 || t1 || t2 || t3){
		int soma = 120;
		
		if(t0 > t1) soma+= abs(t0-t1);
		else if(t0 == t1); else soma+= (40-t1)+t0;
		
		if(t1 < t2) soma+= abs(t1-t2);
		else if(t1 == t2); else soma+= (40-t1)+t2;

		if(t2 > t3) soma+= abs(t2-t3);
		else if(t2 == t3); else soma+= (40-t3)+t2;
		
		soma*=9;
		
		cout << soma << endl;
	}
	
	return 0;
}