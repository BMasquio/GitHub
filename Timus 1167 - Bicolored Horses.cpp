#include <iostream>
using namespace std;

int B[501], W[501];
int T[501][501];

void Imprime(int k, int n){
	int i,j;
	for (i=1; i<=k;i++){
		for (j=1; j<=n;j++)
			cout << T[i][j]<< " ";
		cout << endl;
	}
}

int main() {
	int i,n,j,k,m,temp,horse;
	
	cin >> n;
	cin >> k;
	
	temp = n;
	
	
	
	B[0]=0;
	W[0]=0;
	i=1;
	while(temp){
		
		cin >> horse;
		
		if (horse){
			B[i]=B[i-1]+1;
			W[i]=W[i-1];
		}
		else{
			W[i]=W[i-1]+1;
			B[i]=B[i-1];
		}
		
		i++;
		temp--;
	}
	
	/*
	for(i=1;i<=n;i++){
		cout << B[i] << " ";
	}
	cout << endl;
	for(i=1;i<=n;i++){
		cout << W[i]<< " ";
	}
	cout << endl;
	*/
	
	T[0][0]=0;
	for(i=1;i<=n;i++){
		T[1][i] = B[i]*W[i];
	//	cout << "T[" << 1 << "][" << i << "] = "<< T[1][i] << endl;
		
	}
	
	//caso especial => k = 1
	
	int menor,i1,j1;
	
//	Imprime(1,n);
	
	
	for(i=2;i<=k;i++){
		for(j=i;j<=n;j++){
			
			menor = T[i-1][i-1] + ((B[j]-B[i-1])*(W[j]-W[i-1]));
	//		cout << "menor = " << menor <<endl ;
	//		cout << ((B[j]-B[i-1])*(W[j]-W[i-1])) << endl;
			
			
			for(m=(i-1);m<=(n-1);m++){
		//		cout << "menor = " << "(T["<<i-1<<"]["<<m<<"] + ((B["<<j<<"]-B["<<i-1<<"])*(W["<<j<<"]-W["<<m<<"]))) = "<< (T[i-1][m] + ((B[j]-B[i-1])*(W[j]-W[m]))) << endl;
				if (menor > (T[i-1][m] + ((B[j]-B[m])*(W[j]-W[m])))){
					menor = (T[i-1][m] + ((B[j]-B[m])*(W[j]-W[m])));
				//	cout << "menor = " << "(T["<<i-1<<"]["<<"m"<<"] + ((B["<<j<<"]-B["<<i-1<<"])*(W["<<j<<"]-W["<<m<<"])))" << endl;
				//	cout << "cavalos pretos = " << B[j]-B[m] << endl;
				//	cout << "cavalos brancos = " << W[j]-W[m] << endl;
				}
			}
			
			
			T[i][j] = menor;
	//		cout << "T[" << i << "][" << j << "] = "<< T[i][j] << endl;
		}
	}
	
//	cout << "B[" << n << "] = " << B[n] << endl;
//	cout << "W[" << n << "] = " << W[n] << endl;
	
//	Imprime(k,n);
	
	cout << T[k][n] << endl;
	
	return 0;
}