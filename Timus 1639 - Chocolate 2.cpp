#include <iostream>
using namespace std;

int main() {
	int cortes,maximo,minimo,m,n;
	
	cin >> m >>n;
	
	maximo = max(m,n);
	minimo = min(m,n);
	
	cortes = (maximo-1) + maximo*(minimo-1);
	
	if (cortes%2) cout << "[:=[first]" << endl;
	else cout << "[second]=:]" << endl;
	
	return 0;
}