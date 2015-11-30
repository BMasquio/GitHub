#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
#define NVM 1006
using namespace std;

int C[NVM][NVM], F[NVM][NVM], M[NVM], TIME[NVM], PR[NVM], n, m, nc, np;
bool V[NVM];

int times,mesas,cont;

void ImprimeC(){
        cout<<"Rede:"<<endl;
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (C[i][j] > 0) cout << i << " " << j << "  "<<C[i][j]<<endl;
            }        
        }     
}
void ImprimeF(){
	
		//(3+mesas) até (2+mesas+times)
		
        bool primeiro;
        for(int i=(3+mesas); i<=(2+mesas+times); i++) { 
            primeiro = true;
            
            for(int j=3;j<=(2+mesas);j++) { 
                
                if (F[j][i] > 0){
                	if(!primeiro) cout << " ";
                	cout << (j-2);
                	primeiro = false;
                	cont++;
                }
            }
            cout << endl;
        }     
}

int MF(int s, int t, int minn) {
    V[s] = true;
    if (s==t) return minn;
    
    for(int i=1; i<=n; i++) {
        if (!V[i] && C[s][i] > 0) {
            if (int fm = MF(i, t, min(minn, C[s][i]))) {
                C[s][i] -= fm;  C[i][s] += fm;
                F[s][i] += fm;  F[i][s] -= fm;                
                return fm;
            }
        }
    }
    return 0;
}

void CriaRede(){
     int i,j;

     
     
     for (i=3;i<=(mesas+2);i++){
         C[1][i] = M[i];
         
         
         
         for(j=(mesas+3); j<=(mesas+2+times); j++){
         	C[i][j] = 1;
         }
     }
     
     for (i=(mesas+3);i<=(mesas+2+times);i++){
         C[i][2] = TIME[i];
     }

}

int main() {
    int fmax,i,j;
    
   	//fonte = 1
   	//sumidouro = 2
   	
   	//mesas = 3 até (2+mesas)
   	//times = (3+mesas) até (2+mesas+times)
    
    while(cin>>times>>mesas, times || mesas) {
        memset(C, 0, sizeof(C)); 
        memset(F, 0, sizeof(F));
        memset(V, 0, sizeof(V)); 
        memset(PR, 0, sizeof(PR));
        memset(TIME, 0, sizeof(TIME));
        memset(M, 0, sizeof(M));
        
        int total=0;
        n = mesas+times+2;
        
        for(i=(3+mesas);i<=(mesas+2+times);i++){
        	cin >> TIME[i];
        	total += TIME[i];
        //	cout << TIME[i];
        }
        
        
        for(i=3;i<=(2+mesas);i++){
        	cin >> M[i];
        //	cout << M[i];
        }
        
        
        CriaRede();
        
        fmax = 0;
        
        
        while(int fm = MF(1, 2, INF)) {
            fmax += fm;
            memset(V, 0, sizeof(V));
        }
        
       // cout << fmax << endl;
        
        if(fmax == total){
        	cout << 1 << endl;
        	ImprimeF();
        }
        else cout << 0 << endl;
        
        
	//	cout << fmax << endl;
		
    }
}
