#include <iostream>
#include <string.h>

#define MOD 10000

using namespace std;
int n;
typedef struct matriz{
	int M[110][110];
}matriz;

matriz mat;

matriz Mult(matriz a, matriz b){
	matriz c;
	int i, j, linha, coluna;
	memset(c.M,0,sizeof(c.M));
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	        c.M[i][j]=0;
	        for(int k=0;k<n;k++){
				c.M[i][j]=(c.M[i][j]+(a.M[i][k] * b.M[k][j])%MOD)%MOD;
			}
		}
	}
	
	return c;
}

matriz Potencia(matriz t, int p){
	int i, j;
	/*
	for(i=0;i<(n*n);i++){
			for(j=0;j<(n*n);j++){ cout << " " << t.M[i][j];}
			cout << endl;
	}
	
	cout << "p = " << p << endl;
	cout << endl;
	*/
	
	if(p==1) return t;
	else{
		if(p%2) return Mult(Potencia(t,p-1), mat);
		else{
			matriz temp = Potencia(t, (p/2));
			
			
			
			return Mult(temp, temp);
		}
	}
}



int main() {
	int p, i, temp, j, k, l, inicio, fim;
	
	while(cin >> n >> l){
		
		memset(mat.M,0,sizeof(mat.M));
	
		cin >> inicio >> fim;
		
		for(i=0; i<n; i++){
			for(j=0;j<4;j++){
				cin >> temp;
				mat.M[i][temp-1]++;
			}
		}
		
		if(l==0){if(inicio == fim) cout << 1 << endl; else cout << 0 << endl; continue;}
		/*
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){ cout << " " << mat.M[i][j];}
			cout << endl;
		}
		cout << endl;
		*/
		mat = Potencia(mat, l);
		/*
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){ cout << " " << mat.M[i][j];}
			cout << endl;
		}
		cout << endl;
		*/
		cout << mat.M[inicio-1][fim-1] << endl;
		
	}
	
	return 0;
}