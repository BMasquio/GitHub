#include <iostream>
#include <string.h>
using namespace std;

typedef struct site{
	int t;
	string s;
} site;

int main() {
	int i,n,maior;
	site lista[10];
	int cont = 0;
	cin >> n;
	
	while(n, n--){
		maior = 0;
		for (i=0;i<10;i++){
			cin >> lista[i].s >> lista[i].t;
			if (lista[i].t > maior) maior = lista[i].t;
		}
		
		cout << "Case #" << ++cont << ":" << endl;
		
		for (i=0;i<10;i++){
			if (lista[i].t == maior) cout << lista[i].s << endl;
		}
	}
	
	
	return 0;
}