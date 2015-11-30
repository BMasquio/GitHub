#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n,ant,prox;
	
	while(cin >> n){
		queue<int> fila;
		int tamanho;
		
		if(n==1){cin >> n; cout << 1 << endl; continue;}
		
	
		
		n--;
		
		cin >> ant;
		tamanho=1;
		
		while(n--){
			cin >> prox;
			
		//	cout << endl;
		//	cout << "ant = " << ant << endl;
		//	cout << "prox = " << prox << endl;
			
			if(prox >= ant && n>=0){
				tamanho++;
				ant = prox;
				
				if(n==0) {fila.push(tamanho); break;}
		//		cout << "if" << endl;
		//		cout << "n = " << n << endl;
			}
			else{
		//		cout << "else" << endl;
		//		cout << "n = " << n << endl;
				
				
				fila.push(tamanho);
				tamanho=1;
				
				if(n==0) {fila.push(1); break;}
				
				ant = prox;
			}
			
			
		}
		
	//	cout << fila.size() << endl;
		
		int resp=fila.front();
		fila.pop();
		int ult = resp;
		if(fila.size() == 0){cout << resp << endl; continue;}
		
		while(!fila.empty()){
			
			resp = max(resp, ult+fila.front());
			
			ult = fila.front();
			fila.pop();
		}
		
		cout << resp << endl;
		/*
		while(!fila.empty()){
			cout << " " << fila.top();
			fila.pop();
		}
		cout << endl;
		*/
		
	}
	
	return 0;
}