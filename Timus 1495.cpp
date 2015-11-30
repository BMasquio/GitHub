#include <iostream>
#include <queue>
#include <string>
#include <math.h>

using namespace std;

typedef struct tentativa{
	string str;
	int resto;
} tentativa;

bool Resto[10000002];


int main() {
	int n,i,resto;
	bool achei = false;
	
	cin>>n;
	
	
	if ((n%10==5)||(n%10==0)){
		cout << "Impossible" << endl;
		return 0;
	}
	
	if (n==1){
		cout << "1" << endl;
		return 0;
	}
	
	if (n==2){
		cout << "2" << endl;
		return 0;
	}
	
	tentativa a1,a2;
	queue<tentativa> fila;
	a1.resto = 1%n;
	a1.str = "1";
	a2.resto = 2%n;
	a2.str = "2";

	
	
	
	for(i=0;i<=n;i++) Resto[i] = false;
	
	fila.push(a1);
	fila.push(a2);
	
	while(!(fila.empty())){
		
		
		a1 = fila.front();
		fila.pop();
		
		
		a2 = a1;
		
	
		
		resto = a1.resto;

		
	//	cout << Resto[resto] << endl;
		
		if (!(Resto[resto])&&(a1.str.length())<=30){
			Resto[resto] = true;
			
	//	cout << a1.resto << " " << a1.str << endl;	
			
			
			a1.str = a1.str + "1";
			a2.str = a2.str + "2";

			a1.resto = (a1.resto*10 + 1)%n;
			a2.resto = (a2.resto*10 + 2)%n;
			
			if (a1.resto == 0){
				achei = true;
				break;
			}
			
			if (a2.resto == 0){
				a1=a2;
				achei = true;
				break;
			}
			
			if (!(Resto[a1.resto])) fila.push(a1);
			if (!(Resto[a2.resto])) fila.push(a2);
			
			
		}
		
	}
	
//	for (i=0;i<=n;i++) if (Resto[i]) cout << "Resto[" << i << "] = " << Resto[i] << endl;
	
	if(!achei) cout << "Impossible" << endl;
	else cout << a1.str << endl;
	
	
	return 0;
}