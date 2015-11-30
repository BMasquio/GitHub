#include <iostream>
using namespace std;


int main() {
	int n,m,i,paralelos;
	
	
	
	while(cin >> n, n){
	
		if((n%2==0)&&(n>3)){
			
			m=n*3/2;
			
			cout << m << endl;
			
			//liga o primeiro com o ultimo e o primeiro com o do meio
			cout << "1 " << n << endl;
			cout << "1 " << (n/2)+1 << endl;
			
			//faz o ciclo
			for(i=2;i<=n;i++)
				cout << i << " " << (i-1) << endl;
			
			
			//liga com os paralelos
			paralelos = (n/2)-1;
			for(i = 1; i <= paralelos ; i++){
				cout << (1+i) << " " << (n-i+1) << endl;
			}
			
		}
		else cout << "Impossible" << endl;
	}
	
	return 0;
}