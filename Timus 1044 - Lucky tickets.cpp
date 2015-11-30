#include <iostream>
using namespace std;
 
int main(){
	long long i,n,S[100],a0,a1,a2,a3,soma=0;
	
	cin>>n;
	
	
	for(i=0;i<=36;i++) S[i] = 0;
	
	if (n==2) cout << 10;
	if (n==4) cout << 670;
	
	if (n==6){
		for(a0=0;a0<10;a0++){
			for(a1=0;a1<10;a1++){
				for(a2=0;a2<10;a2++){
					S[a1+a2+a0]++;
			//		cout << "a0 = " << a0 << " a1 = " << a1 << " a2 = " << a2 << " soma = " <<a1+a2+a0 << endl;
				}
			}
		}
 	
 		for(i=0;i<=27;i++){
 			if(S[i] > 0) soma += S[i]*S[i];
 		}
 		cout << soma;
	}
	
	if (n==8){
		for(a0=0;a0<10;a0++){
			for(a1=0;a1<10;a1++){
				for(a2=0;a2<10;a2++){
					for(a3=0;a3<10;a3++){
						S[a1+a2+a0+a3]++;	
					}
				}
			}
		}
 	
 		for(i=0;i<=36;i++) soma += S[i]*S[i];
 		
 		cout << soma;
	}
	return 0;
}