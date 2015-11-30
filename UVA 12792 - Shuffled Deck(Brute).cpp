#include <iostream>
using namespace std;

int main() {
	int n;
	while(cin >> n){
		int pos = 0, cont=0;
		int metade = n/2;
		
		do{
			if(pos < metade) pos=2*pos + 1;
			else pos = 2*(pos-metade);
			cont++;
		}while(pos!=0);
		
		cout << cont << endl;
	}
	return 0;
}