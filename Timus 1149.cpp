#include <iostream>
using namespace std;


int n;


void A(int num){
	int temp=0;
	bool sinal=true;
	
	while(temp != num){
		temp++;
		cout << "sin(" << temp;
		
		
		if (temp != num){
			if (sinal){
				cout << "-";
				sinal=false;
			}
			else{
				cout << "+";
				sinal = true;
			}
		}
	}
	
	while (temp){
		cout << ")";
		temp--;
	}
}

int main() {
	int i,cont=1;
	cin >> n;
	
	

	
	for (i=1;i<n;i++) cout << "(";
	while(n){
//		cout << "(";
		A(cont);
		cont++;
		
		cout << "+" << n;
		n--;
		if (n)	cout << ")";
		
		/*
		((sin(1)+3)sin(1-sin(2))+2)sin(1-sin(2sin(3)))+1
		((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1
		((sin(1)+3)sin(1-sin(2))+2)sin(1-sin(2+sin(3)))+1
		*/
	}
	
	return 0;
}