#include <iostream>
#include <string.h>
using namespace std;

int b1,b2,t,maior,beer;
int M[20010];

int main() {
	
	while(cin >> b1 >> b2 >> t){
		memset(M,-1,sizeof(M));
		//int M[10000]
		M[0] = 0;
		maior = 0;
		beer = 0;
		
		int temp1 = b1;
		int temp2 = b2;
		b1 = min(temp1,temp2);
		b2 = max(temp1,temp2);
		
		int menor = t/b1;
		menor++;
		int primeiro = 0;
		bool prim = true;
		int ult=1,ultimo;
		
		for(int i=0;i<=t;i++){
			//prim = true;
			//for(int j=primeiro; j<=ult+1;j++){
				if (M[i] > -1){
					M[i+b1] = M[i]+1;
			//		if(prim) {primeiro = j+b1; prim = false;}
					M[i+b2] = M[i]+1;
			//		ultimo = j+b2;
				}
			//}
	//		ult = min(ultimo, t);
		}
		
		if(M[t] > -1){ maior = M[t]; beer = 0;}
		else
		for(int i=t;i>=0;i--){
			beer++;
			if (M[i] > -1){
				maior = M[i];
				break;
			}
		}
		
		
		cout << maior;
		if(beer) cout << " " << beer-1;
		cout <<endl;
	}	
	
	return 0;
}