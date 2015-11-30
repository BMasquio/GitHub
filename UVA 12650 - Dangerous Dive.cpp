#include <iostream>
#include <string.h>
using namespace std;

bool A[10000000],foi,prim;

void Zera(){
	memset(A,false,sizeof(A));
}

int main() {
	int temp,a,b;
	
	while(cin >> a >> b){
		Zera();
		for(int i = 1;i <= b; i++){
			cin >> temp;
			A[temp] = true;
		}
		
		if(b == a) cout << "*";
		else{
			for(int i = 1;i <= a; i++)
				if(!A[i]){
					cout << i << " ";
				}
		}
		cout << endl;
	}
	
	return 0;
}