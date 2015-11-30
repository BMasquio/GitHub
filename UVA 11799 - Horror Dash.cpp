#include <iostream>
using namespace std;

int main() {
	int n,m,k,max,cont=0;
	
	cin >>n;
	
	while(n--){
		max=0;
		cin >>m;
		while(m--){
			cin >> k;
			if(k > max) max = k;
		}
		cout << "Case " << ++cont <<": ";
		cout << max << endl;
	}
	
	return 0;
}