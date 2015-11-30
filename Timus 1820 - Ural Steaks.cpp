#include <iostream>
using namespace std;

int mode,lado1,lado2,n,k,V[2000][2000];

int Zera(int z){
	if(z<0) return 0;
	else return z;
}

int Coz(int l1, int l2){
	int k1,i,minimo=9999,j,temp;
	
	if(l1<0) l1=0;
	if(l2<0) l2=0;
	
	if((l1==0)&&(l2==0)) return 0;
	
	if((l1==0)&&(l2<=k)) return 1;
	
	k1 = min(k,l1+l2);
	
	if (V[l1][l2]==-1){
		for (i=0;i<=k1;i++){
	//		cout << l1 << " " << l2 << endl;
			j=k1-i;
	//		cout << i << " = i ; j = " << j << endl;
			if (l1>0){
				if(l2>0){
					temp = 1+Coz(l1-i,Zera(l2-j)+min(i,l1));
	//				if ((l1 == 22)&&(l2 == 978)){
	//					cout << temp  << " tirando " << i << " de l1 = " << l1 << " e " << j << " de l2 = " << l2 << endl;
	//				}
					if (minimo > temp) minimo = temp;
					
					temp = 1+Coz(l1-j,Zera(l2-i)+min(j,l1));
	//				if ((l1 == 22)&&(l2 == 978)){
	//					cout << temp  << " tirando " << j << " de l1 = " << l1 << " e " << i << " de l2 = " << l2  << endl;
	//					cout << i << " = i ; j = " << j << endl;
	//				}
					if (minimo > temp) minimo = temp;
				}else{
					temp = 1+Coz(l1-(i+j),l2+min(l1,i+j));
					if (minimo > temp) minimo = temp;
					break;
				}
			}else{
				temp = 1+Coz(l1,l2-(i+j));
				if (minimo > temp) minimo = temp;
				break;
			}
	}
//	cout << minimo << " com l1 = " << l1 << " e l2 = " << l2 << endl;

	V[l1][l2]=minimo;
	return minimo;
	}
	else return V[l1][l2];
}	

int main() {
	
	int a0,a1;
	
	cin >> lado1 >> k;
	lado2=0;
	
	
	for(a0=0;a0<=1000;a0++)
		for(a1=0;a1<=1000;a1++)
			V[a0][a1] = -1;
	
	V[0][0]=0;
	
	cout << Coz(lado1,lado2) << endl;
	
	/*
	while((lado1>0)||(lado2>0)){
		min++;
		
		if((!lado2)){
			lado1-=k;
			lado2+=k;
			continue;
		}
		
		if((!lado1)){
			lado2-=k;
			continue;
		}
		
		if((lado1)&&(lado1%k==0)){
			lado1-=k;
			lado2+=k;
			continue;
		}
		
		if((lado1)&&(lado1%k>0)){
			lado1-=lado1%k;
			lado2-= k-(lado1%k);
			lado2+=lado1%k;
			continue;
		}
		
		
	}
	*/
	
	return 0;
}