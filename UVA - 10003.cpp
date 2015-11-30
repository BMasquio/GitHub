#include <stdio.h>
#include <iostream>
using namespace std;

int M[60][60];
int L[200];

int n;


void Zera(){
	int i,j;
	for(i=0;i<60;i++)
		for(j=0;j<60;j++)
			M[i][j] = -1;
}

//começa da coluna zero até j
//começa da linha j+1 até 2j+1

int minimo(int linha, int coluna){
	int j,i,temp;
	int menor = 9999999;
	int l,c,k=0;

	while(M[linha][coluna-k]!=0){
		k++;
	}	
//	cout << "k = "<<k<<endl;
	
	for(j=1;j<=k;j++){

		temp = M[linha][coluna-j]+M[linha+k+1-j][coluna];
		
	//	printf(" M[%d][%d] = %d\n",linha,coluna-j,M[linha][coluna-j]);
	//	printf(" M[%d][%d] = %d\n",linha+k+1-j,coluna,M[linha+k+1-j][coluna]);
		
	//	printf("Olhando M[%d][%d]+M[%d][%d]\n",linha,coluna-j,linha+k+1-j,coluna);
		
		if (temp<menor) menor = temp;
		
	}
	
	return menor;
}

int main() {


	int l,i,j;
	
	while(cin>>l,l){
		cin >> n;
		
		Zera();
		
		L[0]=0;
		for(i=1;i<=n;i++){
			cin >> L[i];
		}
		L[n+1]=l;
		
//		for(i=0;i<=n+1;i++){
//			cout << L[i] << endl;
//		}
		
	//				L[2]-L[0]
		//M[0][1] = (5-0) + min(...)
		
	//				L[3]-L[1]
		//M[1][2] = (7-4) + min(...)
		
		//M[2][3] = (8-5) + min(...)
		//M[3][4] = (10-7) + min(...)
		
		
		//			L[5]-L[0]
		//M[0][4] = (10-0)
		
		//M[i][j] = L[j+1] - L[i] + min(...)
		
		
		
		for(i=0;i<(n+1);i++)
			M[i][i]=0;
		
		//linha vai de zero até (n+1)-i
		
		int temp;
		
		for(i=1;i<=(n+1);i++){
			for(j=0;j<=(n+1-i);j++)
				{
	//			cout << "M[" << j << "][" << (j+i) << "]" << endl;
				temp = minimo(j,j+i);
				M[j][j+i] = L[j+i+1] - L[j] + temp;				
	//			cout << "M[" << j << "][" << (j+i) << "] = " << L[j+i+1] << " - " << L[j] << " + " << temp << " = " << M[j][j+i] << endl; 
				}
		}
/*		
		for(i=0;i<(n+1);i++)
			{
			for(j=0;j<(n+1);j++)
				cout << M[i][j] << " ";
			cout << endl;
			}
			//começa da coluna zero até j
			//começa da linha j+1 até 2j+1
*/		
		cout << "The minimum cutting is " << M[0][n] << "." << endl;
	}

	return 0;
}