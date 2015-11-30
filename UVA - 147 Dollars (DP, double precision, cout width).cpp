#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int D[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
unsigned long long T[11]; unsigned long long M[11][300000];

int main() {
	int i,j,k,parcial,inteiro, frac;
	char lixo;
	int temp=10;
	
	memset(M, 0, sizeof(M));
	for(i=0;i<12;i++){
		D[i] /= 5;
		T[temp--] = D[i];
	}
	
	for(i=0;i<12;i++) {D[i]=T[i]; M[i][0] = 1;}
	
	for(i=1;i<=60000;i++) M[0][i] = 1;
	
	for(i=1;i<=10;i++)
		for(j=1;j<=60000;j++){
			if(j-D[i] >= 0){
				M[i][j]+= M[i][j-D[i]];
			}
			M[i][j]+=M[i-1][j];
		}
		/*
	int ate;		 
	ate = 10;
	for(i = 0; i< 11; i++){
		for(j = 0; j< ate; j++)
			cout << M[i][j] << " ";
			cout << endl;}
	*/
	int temp1,temp2;
	while(cin >> inteiro >> lixo >> frac, inteiro||frac){
		//cout<< inteiro << "." << frac << endl;
		temp1=inteiro;temp2=frac;
		inteiro*=100;
		inteiro+=frac;
		inteiro/=5;
		
		double s;
		s = temp1+(double)((double)temp2/(double)100);
		
		cout.width(6);
		cout << fixed << setprecision(2) << s;
	//	cout << temp1 << "." << temp2;
		cout.width(0);
	//	if(temp2 < 100) cout << 0;
		cout.width(17);
		cout << M[10][inteiro] << endl;
		
		
	} 
	
	return 0;
}